import torch
from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
)

model_name = "ahmedheakl/asm2asm-deepseek1.3b-xtokenizer-armv8"

instruction = """<｜begin▁of▁sentence｜>You are a helpful coding assistant assistant on converting from x86 to ARM assembly.
### Instruction:
Convert this x86 assembly into ARM
```asm
{asm_x86}
```
### Response:
```asm
{asm_arm}
"""

model = AutoModelForCausalLM.from_pretrained(
    model_name,
    device_map="auto",
    torch_dtype=torch.bfloat16,
    # attn_implementation="flash_attention_2", # uncomment if you have flash attention installed
)

model.config.use_cache = True

tokenizer = AutoTokenizer.from_pretrained(
    model_name,
    trust_remote_code=True,
)

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
    return outputs.split("```asm\n")[-1].split(f"```{tokenizer.eos_token}")[0].strip()


if __name__ == "__main__":
    x86 = "mov eax, 1"
    arm = inference(x86)
    print(arm)
