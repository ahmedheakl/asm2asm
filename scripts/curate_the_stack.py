from datasets import load_dataset, Dataset
import random
import os
import subprocess
import glob
import re
import json
import sys
from compile_x86_gcc import compile as compile_x86
from compile_arm_gnueabi_gcc import compile as compile_arm
from dotenv import load_dotenv
from tqdm import tqdm

MAX_FILES = 10
OPTIMIZATION_LEVEL = "O0"
HF_ID = f"ahmedheakl/asm2asm_Omix_{MAX_FILES}_gnueabi_gcc"
load_dotenv()


def isfloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False


def data_augger(code):
    yield code
    # modify '#define __ <number>' and 'const int __ = <number>'
    define_regex = r"#define (\S+) ([+-]?[\d*\.]?\d+)"
    const_regex = r"const int (\S+) ([+-]?\d+)"
    index = 0
    code_matches = re.findall(re.compile(define_regex), code)
    redefined_code = ""
    for varname, value in code_matches:
        new_val = value
        if value.isdigit():
            new_val = int(new_val)
            if new_val < 0:
                new_val += random.randint(new_val, -1 * new_val)
            elif new_val > 0:
                new_val += random.randint(-1 * new_val, new_val)
            else:
                new_val += random.randint(-30, 30)
        elif isfloat(value):
            new_val = float(new_val)
            new_val *= random.random()
        define_idx = re.search(define_regex, code[index:])
        redefined_code += (
            code[index : define_idx.start() + index] + f"#define {varname} {new_val}"
        )
        index = define_idx.end() + index
    redefined_code += code[index:]
    new_code = ""
    index = 0
    code_matches = re.findall(re.compile(const_regex), redefined_code)
    for varname, value in code_matches:
        new_val = int(value)
        if new_val > 0:
            new_val += random.randint(-1 * new_val, new_val)
        elif new_val < 0:
            new_val += random.randint(new_val, -1 * new_val)
        else:
            new_val += random.randint(-30, 30)
        const_idx = re.search(const_regex, redefined_code[index:])
        new_code += (
            redefined_code[index : const_idx.start() + index]
            + f"const int {varname} {new_val}"
        )
        index = const_idx.end() + index
    new_code += redefined_code[index:]
    if new_code != code:
        yield new_code


def compile_file(file):

    path_arm = compile_arm(file, optimization_level=OPTIMIZATION_LEVEL)
    path_x86 = compile_x86(file, optimization_level=OPTIMIZATION_LEVEL)
    if path_arm is not None and path_x86 is not None:
        return path_arm, path_x86
    return None

    # def gen_assembly():
    wait = True
    num_samples = 0
    for sample in iter(ds):
        filename = os.path.basename(sample["max_forks_repo_path"])
        if wait or filename == "tempCodeRunnerFile.c":
            wait = False
        if wait:
            continue
        if sample["ext"] == "c" and sample["lang"] == "C":
            try:
                write_to = os.path.join(save_to, filename)
                for source_c in data_augger(sample["content"]):
                    open(write_to, "w").write(source_c)

                    prefix = filename.split(".c")[0]
                    failed = False
                    optimization_level = "O0"
                    x86_path = compile_x86(
                        write_to, optimization_level=optimization_level
                    )
                    arm_path = compile_arm(
                        write_to, optimization_level=optimization_level
                    )
                    new_datapoint = {
                        "source": filename,
                        "c": source_c,
                        "risc_o0": open(f"{save_to}/{prefix}.risc_o0.s").read(),
                        "risc_o1": open(f"{save_to}/{prefix}.risc_o1.s").read(),
                        "risc_o2": open(f"{save_to}/{prefix}.risc_o2.s").read(),
                        "risc_o3": open(f"{save_to}/{prefix}.risc_o3.s").read(),
                        "arm_o0": open(f"{save_to}/{prefix}.arm_o0.s").read(),
                        "arm_o1": open(f"{save_to}/{prefix}.arm_o1.s").read(),
                        "arm_o2": open(f"{save_to}/{prefix}.arm_o2.s").read(),
                        "arm_o3": open(f"{save_to}/{prefix}.arm_o3.s").read(),
                    }
                    yield new_datapoint
                    with open(f"data{int(num_samples/5000)}.jsonl", "a") as wf:
                        wf.write(f"{json.dumps(new_datapoint)}\n")
                    for rf in glob.glob(f"{save_to}/{prefix}*"):
                        os.remove(rf)
                    num_samples += 1
                    if num_samples > 300000 and num_samples % 1000 == 0:
                        import pdb

                        pdb.set_trace()
                        do_break = False
                        if do_break:
                            return
            except:
                continue


def get_files():
    ds = load_dataset("bigcode/the-stack", streaming=True, split="train")
    print("Filtering ...")
    filtered_ds = ds.filter(lambda x: x["ext"] == "c" and x["lang"] == "C")
    save_to = "the_stack_data"
    subprocess.run(["mkdir", "-p", save_to])

    for sample in iter(filtered_ds):
        print("Started ...")
        filename = os.path.basename(sample["max_forks_repo_path"])
        write_to = os.path.join(save_to, filename)
        source_c = sample["content"]
        # for source_c in data_augger(sample["content"]):
        open(write_to, "w").write(source_c)
        yield write_to


def main():
    files = []
    i = 0
    iterator = get_files()
    for i in tqdm(range(MAX_FILES)):
        file = next(iterator)
        files.append(file)
        i += 1
        if i > MAX_FILES:
            break
    print(files)

    # random.shuffle(files)
    # files = files[:MAX_FILES]

    # with mp.Pool(processes=mp.cpu_count()) as pool:
    #     results = list(tqdm(pool.imap(compile_file, files), total=len(files)))

    # paths_arm, paths_x86 = zip(*[r for r in results if r is not None])

    # compilations = {
    #     "x86": [open(path).read() for path in paths_x86],
    #     "arm": [open(path).read() for path in paths_arm],
    # }
    # dataset = datasets.Dataset.from_dict(compilations)
    # dataset.push_to_hub(HF_ID, token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
