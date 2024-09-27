import torch
from datasets import load_dataset
from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
)
from huggingface_hub import login

hf_token = "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"

login(token=hf_token)

model_name = "ahmedheakl/asm2asm-qwen2.5-1.5b-100k-float16-attn"

instruction = """<|im_start|>system
You are a helpful coding assistant assistant on converting from x86 to ARM assembly.<|im_end|>
<|im_start|>user
Convert this x86 assembly into ARM
```asm
{asm_x86}
```<|im_end|>
<|im_start|>assistant
```asm
{asm_arm}
"""


model = AutoModelForCausalLM.from_pretrained(
    model_name,
    device_map="auto",
    token=hf_token,
    torch_dtype=torch.bfloat16,
    attn_implementation="flash_attention_2",
)

model.config.use_cache = True

tokenizer = AutoTokenizer.from_pretrained(
    model_name,
    trust_remote_code=True,
    token=hf_token,
)

dataset = load_dataset("ahmedheakl/asm2asm_eval", split="eval")


def inference(asm_x86: str) -> str:
    prompt = instruction.format(asm_x86=asm_x86, asm_arm="")
    inputs = tokenizer(prompt, return_tensors="pt").to("cuda")
    generated_ids = model.generate(
        **inputs,
        num_return_sequences=1,
        max_new_tokens=8000,
        do_sample=True,
        num_beams=1,
        top_p=0.9,
        eos_token_id=tokenizer.eos_token_id,
        pad_token_id=tokenizer.pad_token_id,
    )
    outputs = tokenizer.batch_decode(generated_ids)[0]
    torch.cuda.empty_cache()
    torch.cuda.synchronize()
    return outputs.split("```asm\n")[-1].split(f"```{tokenizer.eos_token}")[0]


def edit_distance_assembly(gt: str, pred: str) -> int:
    def levenshtein(s1, s2):
        if len(s1) < len(s2):
            return levenshtein(s2, s1)

        if len(s2) == 0:
            return len(s1)

        previous_row = range(len(s2) + 1)
        for i, c1 in enumerate(s1):
            current_row = [i + 1]
            for j, c2 in enumerate(s2):
                insertions = previous_row[j + 1] + 1
                deletions = current_row[j] + 1
                substitutions = previous_row[j] + (c1 != c2)
                current_row.append(min(insertions, deletions, substitutions))
            previous_row = current_row

        return previous_row[-1]

    def preprocess(code):
        code = "\n".join(line.split(";")[0].strip() for line in code.split("\n"))
        code = "\n".join(line for line in code.split("\n") if line.strip())
        return code

    gt_processed = preprocess(gt)
    pred_processed = preprocess(pred)
    distance = levenshtein(gt_processed, pred_processed)

    return distance


def main():
    data = {"pred": [], "gt": [], "input": [], "ed": []}
    total_distance = 0
    for i, example in enumerate(dataset):
        gt = example["arm"]
        pred = inference(example["x86"])
        distance = edit_distance_assembly(gt, pred)
        data["pred"].append(pred)
        data["gt"].append(gt)
        data["input"].append(example["x86"])
        data["ed"].append(distance)
        print(distance)
        total_distance += distance

    print(f"Average edit distance: {total_distance / len(dataset)}")
    import json

    with open("eval_qwen.json", "w") as f:
        json.dump(data, f, indent=4)


if __name__ == "__main__":
    main()
