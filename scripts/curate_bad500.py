import datasets
from dotenv import load_dotenv
import os

load_dotenv()

GOOD_500K = "ahmedheakl/asm2asm_O0_500000_gnueabi_gcc"
BAD_1M = "ahmedheakl/asm2asm_O0_1000000_gnueabi_gcc"
BAD_500K = "ahmedheakl/asm2asm_O0_500k_bad"

ds_good500 = datasets.load_dataset(GOOD_500K, split="train")
ds_bad1M = datasets.load_dataset(BAD_1M, split="train")


# ds_bad500 is the dataset that has no data points from ds_good500
ds_bad500 = ds_bad1M.filter(lambda x: x["x86"] not in ds_good500["x86"])
ds_bad500.push_to_hub(BAD_500K, token=os.getenv("HF_TOKEN"))
