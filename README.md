# CRT: Language-Model Guided Assembly Transpilation

**From CISC to RISC: Language-Model Guided Assembly Transpilation**  
Authors: Ahmed Heakl, Chaimaa Abi, Rania Hossam, Abdulrahman Mahmoud

## Overview

CRT (CISC-RISC Transpiler) is a lightweight, LLM-based assembly transpiler designed to convert x86 assembly (CISC architecture) into ARM assembly (RISC architecture). This repository provides the codebase, models, and benchmarks used in our research, which demonstrates CRT's ability to bridge architectural differences in ISA with a high degree of accuracy and efficiency.

### Key Contributions
1. **First CISC to RISC Transpiler**: Achieves 79.25% accuracy for ARM and 88.68% for RISC-V.
2. **Optimized Performance**: Outperforms Apple’s Rosetta by achieving 1.73x speedup and significant memory and energy efficiency improvements.
3. **Comprehensive Evaluation**: Tested on real-world scenarios on ARM-based hardware and various applications.

## Table of Contents
- [Installation](#installation)
- [Data Preprcessoing](#data-preprcessoing)
- [Usage](#usage)
- [Experiments and Results](#experiments-and-results)
- [Models and Data](#models-and-data)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. **Clone the repository:**
 ```bash
 git clone https://github.com/ahmedheakl/asm2asm
 cd asm2asm
 ```

2. **Install Dependencies**:
 ```bash
 pip install -r requirements.txt
 ```

## Data Preprcessoing
1. Donwload the [AnghaBench Dataset](https://github.com/brenocfg/AnghaBench)
2. Create a `.env` file and add you huggingface token `HF_TOKEN`.
3. Preprocess and push to huggingface using the `scripts/curate_dataset.py` script. Just modify the `DATA_ROOT` to be the directory where your AnghaBench is located.
```bash
python scripts/curate_dataset.py 
```

## Usage

All our models and dataset are pushed to [huggingface](https://huggingface.co/collections/ahmedheakl/cisc-to-risc-672727bd996db985473d146e). To use our best model, 
```python
import torch
from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
)
from tqdm import tqdm


model_name = "ahmedheakl/asm2asm-deepseek1.3b-xtokenizer-arm"

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
    token=hf_token,
    device_map="auto",
    torch_dtype=torch.bfloat16,
)

model.config.use_cache = True

tokenizer = AutoTokenizer.from_pretrained(
    model_name,
    trust_remote_code=True,
    token=hf_token,
)

def inference(asm_x86: str) -> str:
    prompt = instruction.format(asm_x86=asm_x86, asm_arm="")
    inputs = tokenizer(prompt, return_tensors="pt").to("cuda")
    generated_ids = model.generate(
        **inputs,
        use_cache=True,
        num_return_sequences=1,
        max_new_tokens=8000,
        do_sample=False,
        num_beams=4,
        eos_token_id=tokenizer.eos_token_id,
        pad_token_id=tokenizer.pad_token_id,
    )
    outputs = tokenizer.batch_decode(generated_ids)[0]
    torch.cuda.empty_cache()
    torch.cuda.synchronize()
    return outputs.split("```asm\n")[-1].split(f"```{tokenizer.eos_token}")[0]

x86 = "DWORD PTR -248[rbp] movsx rdx"
inference(x86)
```


## Experiments and Results

| **Model**                        | **Average Edit Distance** (↓) | **Exact Match** (↑) | **Test Accuracy** (↑) |
|----------------------------------|-------------------------------|----------------------|------------------------|
| GPT4o                  | 1296                          | 0%                  | 8.18%                  |
| DeepSeekCoder2-16B  | 1633                          | 0%                  | 7.36%                  |
| Yi-Coder-9B          | 1653                          | 0%                  | 6.33%                  |
| **Yi-coder-1.5B**                | 275                           | 16.98%              | 49.69%                 |
| **DeepSeekCoder-1.3B**           | 107                           | 45.91%              | 77.23%                 |
| **DeepSeekCoder-1.3B-xTokenizer-int4** | 119                    | 46.54%              | 72.96%                 |
| **DeepSeekCoder-1.3B-xTokenizer-int8** | **96**                | 49.69%              | 75.47%                 |
| **DeepSeekCoder-1.3B-xTokenizer**      | 165                    | **50.32%**          | **79.25%**             |

*Table: Comparison of models' performance on the* _x86 to ARM_ *transpilation task, measured by Edit Distance, Exact Match, and Test Accuracy. The top portion lists pre-existing models, while the bottom portion lists models trained by us. Arrows (↑, ↓) indicate whether higher or lower values are better for each metric. The best results are highlighted in bold.*


| **Model**                        | **Average Edit Distance** (↓) | **Exact Match** (↑) | **Test Accuracy** (↑) |
|----------------------------------|-------------------------------|----------------------|------------------------|
| GPT4o                  | 1293                          | 0%                  | 7.55%                  |
| DeepSeekCoder2-16B  | 1483                          | 0%                  | 6.29%                  |
| **DeepSeekCoder-1.3B-xTokenizer-int4** | 112                    | 14.47%              | 68.55%                 |
| **DeepSeekCoder-1.3B-xTokenizer-int8** | 31                     | 69.81%              | 88.05%                 |
| **DeepSeekCoder-1.3B-xTokenizer**      | **27**                 | **69.81%**          | **88.68%**             |

*Table: Comparison of models' performance on the* _x86 to RISCv64_ *transpilation task.*


## Contributing

We welcome contributions! If you're interested in improving CRT or expanding it to other architectures, please create a pull request or an issue and we will take care of it ASAP.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
