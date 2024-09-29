import os
import glob
from tqdm import tqdm
import multiprocessing as mp

from dotenv import load_dotenv
import datasets

from compile_x86_gcc import compile as compile_x86
from compile_arm_gnueabi_gcc import compile as compile_arm

DATA_ROOT = "eval"
OPTIMIZATION_LEVEL = "O2"
HF_ID = f"ahmedheakl/asm2asm_{OPTIMIZATION_LEVEL}_eval_gnueabi_gcc"
load_dotenv()


def get_files(dir: str):
    return glob.glob(f"{dir}/**/code.c", recursive=True)


def compile_file(file):
    path_arm = compile_arm(file, optimization_level=OPTIMIZATION_LEVEL)
    path_x86 = compile_x86(file, optimization_level=OPTIMIZATION_LEVEL)
    if path_arm is not None and path_x86 is not None:
        return path_arm, path_x86, file
    return None


def main():
    files = get_files(DATA_ROOT)
    with mp.Pool(processes=mp.cpu_count()) as pool:
        results = list(tqdm(pool.imap(compile_file, files), total=len(files)))

    paths_arm, paths_x86, files = zip(*[r for r in results if r is not None])

    compilations = {
        "files": files,
        "x86": [open(path).read() for path in paths_x86],
        "arm": [open(path).read() for path in paths_arm],
    }
    dataset = datasets.Dataset.from_dict(compilations)
    dataset.push_to_hub(HF_ID, token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
