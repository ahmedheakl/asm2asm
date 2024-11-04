import os
import glob
import json
from tqdm import tqdm
import multiprocessing as mp

from dotenv import load_dotenv
import datasets
import random

from compile_x86_gcc import compile as compile_x86

DATA_ROOT = "asm_data"
OPTIMIZATION_LEVEL = "O0"
META_JSON = "arm_metadata.json"
HF_ID = "ahmedheakl/asm2asm_mac_x86_data"
load_dotenv()


def get_files():
    with open(META_JSON) as f:
        metadata = json.load(f)
    files = [os.path.join(DATA_ROOT, f["original_file"]) for f in metadata]
    return files


def compile_file(file):
    path_x86 = compile_x86(file, optimization_level=OPTIMIZATION_LEVEL)
    if path_x86 is not None:
        return path_x86
    return None


def main():
    files = get_files()

    with mp.Pool(processes=mp.cpu_count()) as pool:
        results = list(tqdm(pool.imap(compile_file, files), total=len(files)))

    paths_x86 = [r for r in results if r is not None]

    compilations = {
        "path": paths_x86,
        "x86": [open(path).read() for path in paths_x86],
    }
    dataset = datasets.Dataset.from_dict(compilations)
    dataset.push_to_hub(HF_ID, token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
