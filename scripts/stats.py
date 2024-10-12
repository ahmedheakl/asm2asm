import json


files = {
    "500-2ep-4b": "eval_deepseek_Omix_500k_x86_O0_2ep_beam4_gnueabi_gcc.json",
    "500-2ep-2b": "eval_deepseek_Omix_500k_x86_O0_2ep_beam2_gnueabi_gcc.json",
    "1m": "eval_deepseek-1.3b-1M-beam1-x86-O0-arm-gnueabi-gcc.json",
    "1m-2b": "eval_deepseek-1.3b-1M-beam2-x86-O0-arm-gnueabi-gcc.json",
    "1m-4b": "eval_deepseek-1.3b-1M-beam4-x86-O0-arm-gnueabi-gcc.json",
    "1m-8b": "eval_deepseek-1.3b-1M-beam8-x86-O0-arm-gnueabi-gcc.json",
}
# path = "results/eval_deepseek_Omix_150k_gnueabi_gcc.json"


def eval_stats(name, path):

    with open(path, "r") as f:
        data = json.load(f)

    ed = data["ed"]
    print(name)
    print(f"Exact match: {len([f for f in ed if f == 0])}")
    print(f"30 CER: {len([f for f in ed if f <= 30])}")
    print(f"Edit distance: {round(sum(ed) / len(ed))}")

    print("----")


for k, v in files.items():
    eval_stats(k, f"results/{v}")
