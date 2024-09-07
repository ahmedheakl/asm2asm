from tqdm import tqdm
import datasets
import random
from compile_arm_clang import compile as compile_arm_clang
from compile_x86_clang import compile as compile_x86_clang
import glob

DATA_ROOT = "data"
MAX_FILES = 100
HF_ID = f"ahmedheakl/asm2asm_{MAX_FILES}"


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
            paths_arm.append(compile_arm_clang(file))
            paths_x86.append(compile_x86_clang(file))
            pbar.update(1)
    compilations = {
        "x86": [open(path).read() for path in paths_x86],
        "arm": [open(path).read() for path in paths_arm],
    }
    dataset = datasets.Dataset.from_dict(compilations)
    dataset.push_to_hub(HF_ID, token="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")


if __name__ == "__main__":
    main()