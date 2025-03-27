import subprocess
from tqdm import tqdm
from multiprocessing import Pool, cpu_count
from glob import glob

def run_command(command):
    try:
        result = subprocess.run(
            command, shell=True, check=True, capture_output=True, text=True, timeout=20
        )
        return True, result.stdout
    except subprocess.CalledProcessError as e:
        return False, e.stderr

    except subprocess.TimeoutExpired as e:
        return False, f"Timeout expired: {e}"

compilation_level = "-O2"

def process_test(file):
    asm_path = file.replace("code.c", "asm.s")
    success, output = run_command(f"clang -arch arm64 -S {file} -o {asm_path} {compilation_level}")
    if not success:
        print(f"Failed to compile {file}: {output}")
        return "Failed", file

    out_path = asm_path.replace(".s", ".o")
    success, output = run_command(f"clang -arch arm64 -c {asm_path} -o {out_path} {compilation_level}")
    if not success:
        print(f"Failed to assemble {file}: {output}")
        return "Failed", file

    test_path = file.replace("code.c", "test.c")
    test_out_path = test_path.replace(".c", ".o")
    success, output = run_command(
        f"clang -arch arm64 -c {test_path} -o {test_out_path} {compilation_level}"
    )
    if not success:
        print(f"Failed to compile test for {file}: {output}")
        return "Failed", file

    linked_path = asm_path.replace(".s", "")
    success, output = run_command(
        f"clang -arch arm64 {out_path} {test_out_path} -o {linked_path} {compilation_level}"
    )
    if not success:
        print(f"Failed to link {file}: {output}")
        return "Failed", file

    success, output = run_command(f"./{linked_path}")
    if not success:
        print(f"Test failed for {file}: {output}")
        return "Failed", file

    return "success", file



if __name__ == "__main__":
    data_root = "eval"
    test_data = glob(f"{data_root}/problem*/code.c")
    total_tests = len(test_data)
    num_processes = cpu_count()
    with Pool(num_processes) as pool:
        results = list(tqdm(pool.imap(process_test, test_data), total=total_tests))

    failed_files = [file.replace(f"{data_root}/", "") for (result, file) in results if result != "success"]
    successful = len([result for result in results if result == "success"])
    
    accuracy = (successful / total_tests) * 100
    if len(failed_files) > 0:
        print(f"#### FAILED FILES ####\n{failed_files}")
    print(
        f"Tests completed. Successful: {successful}, Failed: {len(failed_files)}, Total: {total_tests}"
    )
    print(f"Accuracy: {accuracy:.2f}%")
