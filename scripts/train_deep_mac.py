import torch
from datasets import load_dataset
from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
    TrainingArguments,
)
from trl import SFTTrainer, DataCollatorForCompletionOnlyLM


model_name = "deepseek-ai/deepseek-coder-1.3b-instruct"
new_model = "asm2asm-deepseek-1.3b-500k-mac-2p-x86-O0-arm-gnueabi-gcc"

output_dir = new_model
num_train_epochs = 2
per_device_train_batch_size = 1
gradient_accumulation_steps = 4
gradient_checkpointing = True
max_grad_norm = 0.3
learning_rate = 2e-4
weight_decay = 0.001
optim = "paged_adamw_32bit"
lr_scheduler_type = "linear"
max_steps = -1
warmup_ratio = 0
group_by_length = False
save_steps = 1000
logging_steps = 25
save_total_limit = 1

# SFT parameters
max_seq_length = 16_000
packing = False
device_map = "auto"


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
    device_map=device_map,
    token=hf_token,
    torch_dtype=torch.bfloat16,
)

model.config.use_cache = False
model.config.pretraining_tp = 1

tokenizer = AutoTokenizer.from_pretrained(
    model_name,
    trust_remote_code=True,
    token=hf_token,
)
tokenizer.padding_side = "right"
# x86_registers = [
#     "rax",
#     "rbx",
#     "rcx",
#     "rdx",
#     "rsi",
#     "rdi",
#     "rbp",
#     "rsp",
#     "r8",
#     "r9",
#     "r10",
#     "r11",
#     "r12",
#     "r13",
#     "r14",
#     "r15",
#     "eax",
#     "ebx",
#     "ecx",
#     "edx",
#     "esi",
#     "edi",
#     "esp",
#     "r8d",
#     "r9d",
#     "r10d",
#     "r11d",
#     "r12d",
#     "r13d",
#     "r14d",
#     "r15d",
#     "ax",
#     "bx",
#     "cx",
#     "dx",
#     "si",
#     "di",
#     "bp",
#     "sp",
#     "al",
#     "bl",
#     "cl",
#     "dl",
#     "spl",
#     "ah",
#     "bh",
#     "ch",
#     "dh",
#     "cs",
#     "ds",
#     "ss",
#     "es",
#     "fs",
#     "gs",
#     "rip",
# ]
# most_used_x86_instructions = [
#     "mov",
#     "add",
#     "sub",
#     "mul",
#     "div",
#     "inc",
#     "dec",
#     "and",
#     "or",
#     "xor",
#     "not",
#     "neg",
#     "shr",
#     "sal",
#     "sar",
#     "cmp",
#     "test",
#     "jmp",
#     "je",
#     "jne",
#     "jg",
#     "jge",
#     "jl",
#     "jle",
#     "call",
#     "ret",
#     "push",
#     "pop",
#     "nop",
#     "int",
# ]


# arm_registers = [
#     "r0",
#     "r1",
#     "r2",
#     "r3",
#     "r4",
#     "r5",
#     "r6",
#     "r7",
#     "r8",
#     "r9",
#     "r10",
#     "sp",
#     "lr",
#     "pc",
#     "c0",
#     "c1",
#     "c2",
#     "c3",
#     "c4",
#     "c5",
#     "c6",
# ]
# most_used_arm_instructions = [
#     "mov",
#     "add",
#     "sub",
#     "mul",
#     "div",
#     "inc",
#     "dec",
#     "and",
#     "or",
#     "xor",
#     "not",
#     "neg",
#     "cmp",
#     "test",
#     "b",
#     "beq",
#     "bne",
#     "bgt",
#     "bge",
#     "blt",
#     "ble",
#     "bl",
#     "bx",
#     "blx",
#     "blx",
#     "push",
#     "pop",
#     "nop",
#     "swi",
#     "bx",
#     "ldr",
# ]
# special = ["PTR", "QWORD", "DWORD"]
# new_tokens = (
#     x86_registers
#     + most_used_x86_instructions
#     + arm_registers
#     + most_used_arm_instructions
#     + special
# )
# new_tokens = set(new_tokens) - set(tokenizer.vocab.keys())
# tokenizer.add_tokens(list(new_tokens))
# model.resize_token_embeddings(len(tokenizer))


dataset = load_dataset("ahmedheakl/asm2asm_traindata", split="train")
EOS_TOKEN = tokenizer.eos_token


def formatting_prompts_func(examples):
    asms_x86 = examples["x86_assembly"]
    asms_arm = examples["arm_assembly"]
    texts = []
    for asm_x86, asm_arm in zip(asms_x86, asms_arm):
        text = (
            instruction.format(asm_x86=asm_x86, asm_arm=asm_arm) + "\n```" + EOS_TOKEN
        )
        texts.append(text)
    return {
        "text": texts,
    }


train_dataset_mapped = dataset.map(formatting_prompts_func, batched=True)
print("Mapping done")


def filter_func(examples):
    input_ids_batch = tokenizer(examples["text"], truncation=False)["input_ids"]
    return [len(input_ids) <= max_seq_length for input_ids in input_ids_batch]


train_dataset_mapped = train_dataset_mapped.filter(
    filter_func, batched=True, batch_size=10000
)
print(len(train_dataset_mapped))


training_arguments = TrainingArguments(
    output_dir=output_dir,
    num_train_epochs=num_train_epochs,
    per_device_train_batch_size=per_device_train_batch_size,
    gradient_accumulation_steps=gradient_accumulation_steps,
    optim=optim,
    save_steps=save_steps,
    logging_steps=logging_steps,
    learning_rate=learning_rate,
    weight_decay=weight_decay,
    fp16=False,
    bf16=True,
    max_grad_norm=max_grad_norm,
    max_steps=max_steps,
    warmup_ratio=warmup_ratio,
    group_by_length=group_by_length,
    lr_scheduler_type=lr_scheduler_type,
    report_to="all",
    push_to_hub=True,
    save_total_limit=save_total_limit,
    # use_liger_kernel=True,
)

response_template = "### Response:\n```asm\n"
collator = DataCollatorForCompletionOnlyLM(response_template, tokenizer=tokenizer)

trainer = SFTTrainer(
    model=model,
    train_dataset=train_dataset_mapped,
    dataset_text_field="text",
    max_seq_length=max_seq_length,
    tokenizer=tokenizer,
    args=training_arguments,
    packing=packing,
    data_collator=collator,
)

trainer.train()
trainer.push_to_hub(f"ahmedheakl/{output_dir}")
