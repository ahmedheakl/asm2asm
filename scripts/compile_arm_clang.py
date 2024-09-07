import glob
import subprocess
import multiprocessing
import argparse

OPT = ["O0", "O1", "O2", "O3"]  # Optimization states


def compile(input_file, optimization_level="O0") -> str:
    base_output_file = input_file.replace(".c", "")
    assert (
        optimization_level in OPT
    ), f"Invalid optimization level: {optimization_level}"
    input_text = open(input_file).read()  # Read input file
    if "/* Variables and functions */" in input_text:
        # Exclude macro and types
        input_text = input_text.split("/* Variables and functions */")[-1]
        input_text = "\n\n".join(input_text.split("\n\n")[1:])  # Exclude variables
        ##### begin of remove __attribute__
        input_text = input_text.replace("__attribute__((used)) ", "")
        ##### end of remove __attribute__
    try:
        asm_output = (
            base_output_file
            + "_"
            + optimization_level
            + "_"
            + "arm"
            + "_"
            + "clang"
            + ".s"
        )
        subprocess.run(
            [
                "clang",
                "-S",
                "-target",
                "arm-none-eabi",  # Target ARM architecture
                "-mcpu=cortex-a53",  # Specify the ARM CPU (adjust as needed)
                "-o",
                asm_output,
                input_file,
                "-" + optimization_level,
            ],
            check=True,
            stderr=subprocess.PIPE,
        )
        return asm_output

    except Exception as e:
        print(f"Error in file {input_file}: {e}")
        return


def parse_args():
    parser = argparse.ArgumentParser(description="Compile C files.")
    parser.add_argument(
        "--root",
        required=True,
        help="Root directory where AnghaBench/folder files are located.",
    )
    args = parser.parse_args()
    return args


def main():
    args = parse_args()
    root = args.root
    files = glob.glob(f"{root}/**/*.c", recursive=True)

    with multiprocessing.Pool(4) as pool:
        pool.map(compile, files)


if __name__ == "__main__":
    main()
