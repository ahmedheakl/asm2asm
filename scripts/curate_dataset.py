import os
import glob
import json
from tqdm import tqdm
import multiprocessing as mp

from dotenv import load_dotenv
import datasets
import random

# from compile_arm_clang import compile as compile_arm
# from compile_x86_clang import compile as compile_x86
# from compile_arm_gcc import compile as compile_arm
from compile_x86_gcc import compile as compile_x86
from compile_arm_gnueabi_gcc import compile as compile_arm

DATA_ROOT = "data"
MAX_FILES = 500_000
OPTIMIZATION_LEVEL = "O0"
OPTIMIZATION_PERCENTAGE = 0.1
HF_ID = f"ahmedheakl/asm2asm_Omix_{MAX_FILES}_gnueabi_gcc"
load_dotenv()


def get_files(dir: str):
    return glob.glob(f"{dir}/**/*.c", recursive=True)


def compile_file(file):
    optimization_level = "O2" if random.random() <= OPTIMIZATION_PERCENTAGE else "O0"
    path_arm = compile_arm(file, optimization_level=optimization_level)
    path_x86 = compile_x86(file, optimization_level=optimization_level)
    if path_arm is not None and path_x86 is not None:
        return path_arm, path_x86
    return None


def main():
    files = get_files(DATA_ROOT)
    random.shuffle(files)
    files = files[:MAX_FILES]

    with mp.Pool(processes=mp.cpu_count()) as pool:
        results = list(tqdm(pool.imap(compile_file, files), total=len(files)))

    paths_arm, paths_x86 = zip(*[r for r in results if r is not None])

    compilations = {
        "x86": [open(path).read() for path in paths_x86],
        "arm": [open(path).read() for path in paths_arm],
    }
    dataset = datasets.Dataset.from_dict(compilations)
    dataset.push_to_hub(HF_ID, token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
