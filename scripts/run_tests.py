import json
import subprocess
from tqdm import tqdm
from multiprocessing import Pool, cpu_count


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
    pred, file, ed = data
    pred_path = file.replace("code.c", "pred.s")
    with open(pred_path, "w") as f:
        f.write(pred)

    out_path = pred_path.replace(".s", ".o")
    success, output = run_command(f"arm-linux-gnueabi-as {pred_path} -o {out_path}")
    if not success:
        return f"Failed to assemble {file}: {output}", ed

    test_path = file.replace("code.c", "test.c")
    test_out_path = test_path.replace(".c", ".o")
    success, output = run_command(
        f"arm-linux-gnueabi-gcc -c {test_path} -o {test_out_path}"
    )
    if not success:
        return f"Failed to compile test for {file}: {output}", ed

    linked_path = pred_path.replace(".s", "")
    success, output = run_command(
        f"arm-linux-gnueabi-gcc {out_path} {test_out_path} -o {linked_path}"
    )
    if not success:
        return f"Failed to link {file}: {output}", ed

    success, output = run_command(f"qemu-arm -L /usr/arm-linux-gnueabi {linked_path}")
    if not success:
        return f"Test failed for {file}: {output}", ed

    return "success", ed


if __name__ == "__main__":
    results_path = "results/eval_deepseek_gnueabi_gcc.json"

    with open(results_path, "r") as f:
        data = json.load(f)

    total_tests = len(data["pred"])
    test_data = list(zip(data["pred"], data["files"], data["ed"]))
    num_processes = max(1, cpu_count() // 2)

    failed = 0
    successful = 0

    with Pool(num_processes) as pool:
        results = list(tqdm(pool.imap(process_test, test_data), total=total_tests))

    success_ed = []
    failed_errors = []
    for result in results:
        result, ed = result
        if result == "success":
            successful += 1
            success_ed.append(ed)
        else:
            failed += 1
            # print(result)
            failed_errors.append(result)

    accuracy = (successful / total_tests) * 100
    print(
        f"Tests completed. Successful: {successful}, Failed: {failed}, Total: {total_tests}"
    )
    print(f"Accuracy: {accuracy:.2f}%")
    import matplotlib.pyplot as plt

    plt.hist(success_ed, bins=20)
    plt.xlabel("Edit Distance")
    plt.ylabel("Frequency")
    plt.title("Edit Distance of Successful Tests")
    plt.show()

    # group failed errors
    error_counts = {}
    for error in failed_errors:
        if error.split("\n")[-1] != "":
            error = error.split("\n")[-1]
        else:
            error = error.split("\n")[-2]
        if error not in error_counts:
            error_counts[error] = 0
        error_counts[error] += 1
    print(error_counts)
