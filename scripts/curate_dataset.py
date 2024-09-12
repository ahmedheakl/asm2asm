import os
import glob
from tqdm import tqdm

from dotenv import load_dotenv
import datasets
import random

from compile_arm_clang import compile as compile_arm_clang
from compile_x86_clang import compile as compile_x86_clang

DATA_ROOT = "data"
MAX_FILES = 10000
HF_ID = f"ahmedheakl/asm2asm_{MAX_FILES}"
load_dotenv()


def get_files(dir: str):
    return glob.glob(f"{dir}/**/*.c", recursive=True)


def main():
    files = get_files(DATA_ROOT)
    random.shuffle(files)
    files = files[:MAX_FILES]
    paths_x86 = []
    paths_arm = []
    with tqdm(total=MAX_FILES) as pbar:
        for file in files:
            path_arm = compile_arm_clang(file)
            path_x86 = compile_x86_clang(file)
            if path_arm is not None and path_x86 is not None:
                paths_arm.append(path_arm)
                paths_x86.append(path_x86)
            pbar.update(1)
    compilations = {
        "x86": [open(path).read() for path in paths_x86],
        "arm": [open(path).read() for path in paths_arm],
    }
    dataset = datasets.Dataset.from_dict(compilations)
    dataset.push_to_hub(HF_ID, token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
