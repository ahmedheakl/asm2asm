from dotenv import load_dotenv
import datasets

load_dotenv()
DATASET_PATH = "ahmedheakl/asm2asm_eval"


def predict(asm_x86: str) -> str:
    return asm_x86


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
    dataset = datasets.load_dataset(DATASET_PATH, split="eval")

    total_distance = 0
    for example in dataset:
        gt = example["arm"]
        pred = predict(example["x86"])
        distance = edit_distance_assembly(gt, pred)
        total_distance += distance

    print(f"Average edit distance: {total_distance / len(dataset)}")


if __name__ == "__main__":
    main()
