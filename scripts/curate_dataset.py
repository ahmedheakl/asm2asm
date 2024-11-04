import os
import glob
import json
from tqdm import tqdm
import multiprocessing as mp
from transformers import AutoTokenizer

from dotenv import load_dotenv
import datasets
import random

# from compile_arm_clang import compile as compile_arm
# from compile_x86_clang import compile as compile_x86
# from compile_arm_gcc import compile as compile_arm
from compile_x86_gcc import compile as compile_x86

# from compile_arm_gnueabi_gcc import compile as compile_arm
from compile_riscv5_gcc import compile as compile_risc

DATA_ROOT = "asm_data"
MAX_FILES = 500_000
OPTIMIZATION_LEVEL = "O0"
OPTIMIZATION_PERCENTAGE = 0.1
HF_ID = f"ahmedheakl/asm2asm_O0_{MAX_FILES}_risc"
load_dotenv()


def get_files(dir: str):
    return glob.glob(f"{dir}/**/*.c", recursive=True)


def compile_file(file):
    # optimization_level = "O2" if random.random() <= OPTIMIZATION_PERCENTAGE else "O0"
    path_risc = compile_risc(file, optimization_level=OPTIMIZATION_LEVEL)
    path_x86 = compile_x86(file, optimization_level=OPTIMIZATION_LEVEL)
    if path_risc is not None and path_x86 is not None:
        return path_risc, path_x86
    return None


def main():
    files = get_files(DATA_ROOT)
    random.shuffle(files)
    files = files[:MAX_FILES]

    with mp.Pool(processes=mp.cpu_count()) as pool:
        results = list(tqdm(pool.imap(compile_file, files), total=len(files)))

    paths_risc, paths_x86 = zip(*[r for r in results if r is not None])
    paths_risc = paths_risc[:MAX_FILES]
    paths_x86 = paths_x86[:MAX_FILES]
    # Split the paths into two halves
    mid_index = len(paths_x86) // 2

    # First half
    compilations = {
        "x86": [open(path).read() for path in paths_x86[:mid_index]],
        "risc": [open(path).read() for path in paths_risc[:mid_index]],
    }
    dataset_1 = datasets.Dataset.from_dict(compilations)
    dataset_1.push_to_hub(HF_ID + "_1", token=os.getenv("HF_TOKEN"))

    del compilations

    # Second half
    compilations = {
        "x86": [open(path).read() for path in paths_x86[mid_index:]],
        "risc": [open(path).read() for path in paths_risc[mid_index:]],
    }
    dataset_2 = datasets.Dataset.from_dict(compilations)
    dataset_2.push_to_hub(HF_ID + "_2", token=os.getenv("HF_TOKEN"))

    # tokenizer = AutoTokenizer.from_pretrained(
    #     "ahmedheakl/asm2asm-deepseek-1.3b-500k-2ep-tokenizer-x86-O0-arm-gnueabi-gcc",
    #     trust_remote_code=True,
    #     token=os.getenv("HF_TOKEN"),
    # )

    # def filter_func(examples):
    #     texts = [
    #         instruction.format(asm_x86=asm_x86, asm_arm=asm_arm)
    #         for asm_x86, asm_arm in zip(examples["x86"], examples["arm"])
    #     ]
    #     input_ids_batch = tokenizer(texts, truncation=False)["input_ids"]
    #     return [len(input_ids) <= 16_000 for input_ids in input_ids_batch]

    # train_dataset_mapped = train_dataset_mapped.filter(
    #     filter_func, batched=True, batch_size=10000
    # )

    # train_dataset_mapped.push_to_hub(HF_ID + "-filtered", token=os.getenv("HF_TOKEN"))


if __name__ == "__main__":
    main()
