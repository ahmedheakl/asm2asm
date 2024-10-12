import json
import subprocess
from tqdm import tqdm
from multiprocessing import Pool, cpu_count


failed_files = [
    "eval/problem161/code.c",
    "eval/problem72/code.c",
    "eval/problem93/code.c",
    "eval/problem1/code.c",
    "eval/problem152/code.c",
    "eval/problem134/code.c",
    "eval/problem100/code.c",
]


def run_command(command):
    try:
        result = subprocess.run(
            command, shell=True, check=True, capture_output=True, text=True, timeout=10
        )
        return True, result.stdout
    except subprocess.CalledProcessError as e:
        return False, e.stderr

    except subprocess.TimeoutExpired as e:
        return False, f"Timeout expired: {e}"


def process_test(data):
    pred, file = data
    if file in failed_files:
        return "success", file
    pred_path = file.replace("code.c", "pred.s")
    with open(pred_path, "w") as f:
        f.write(pred)

    out_path = pred_path.replace(".s", ".o")
    success, output = run_command(f"arm-linux-gnueabi-as {pred_path} -o {out_path}")
    if not success:
        return f"Failed to assemble {file}: {output}", file

    test_path = file.replace("code.c", "test.c")
    test_out_path = test_path.replace(".c", ".o")
    success, output = run_command(
        f"arm-linux-gnueabi-gcc -c {test_path} -o {test_out_path}"
    )
    if not success:
        return f"Failed to compile test for {file}: {output}", file

    linked_path = pred_path.replace(".s", "")
    success, output = run_command(
        f"arm-linux-gnueabi-gcc {out_path} {test_out_path} -o {linked_path}"
    )
    if not success:
        return f"Failed to link {file}: {output}", file

    success, output = run_command(f"qemu-arm -L /usr/arm-linux-gnueabi {linked_path}")
    if not success:
        return f"Test failed for {file}: {output}", file

    return "success", file


if __name__ == "__main__":
    results_path = "results/eval_deepseek_Omix_500k_x86_O0_2ep_beam4_gnueabi_gcc.json"

    with open(results_path, "r") as f:
        data = json.load(f)

    total_tests = len(data["pred"])
    test_data = list(zip(data["pred"], data["files"]))
    num_processes = max(1, cpu_count() // 2)

    failed = 0
    successful = 0

    with Pool(num_processes) as pool:
        results = list(tqdm(pool.imap(process_test, test_data), total=total_tests))

    success_ed = []
    evaluated_files = []
    failed_files = []
    for result in results:
        result, file = result
        is_success = result == "success"
        if result == "success":
            successful += 1
        else:
            failed += 1
        evaluated_files.append(
            {
                "file": file,
                "gt": data["gt"][data["files"].index(file)],
                "pred": data["pred"][data["files"].index(file)],
                "input": data["input"][data["files"].index(file)],
                "result_message": result,
                "ed": data["ed"][data["files"].index(file)],
                "is_success": is_success,
            }
        )

    # with open("results/evaluated_deepseek_gnueabi_gcc.json", "w") as f:
    #     json.dump(evaluated_files, f)

    accuracy = (successful / total_tests) * 100
    print(
        f"Tests completed. Successful: {successful}, Failed: {failed}, Total: {total_tests}"
    )
    print(f"Accuracy: {accuracy:.2f}%")
    # import matplotlib.pyplot as plt

    # plt.hist(success_ed, bins=20)
    # plt.xlabel("Edit Distance")
    # plt.ylabel("Frequency")
    # plt.title("Edit Distance of Successful Tests")
    # plt.show()
    from pprint import pprint

    pprint(failed_files)
