import os
import sys

def create_main_c_if_not_exists(path):
    for root, dirs, files in os.walk(path):
        if "main.c" not in files:
            main_c_path = os.path.join(root, "main.c")
            with open(main_c_path, 'w') as f:
                f.write("// This is an auto-generated main.c file\n")
                f.write("#include <stdio.h>\n\n")
                f.write("int main() {\n")
                f.write("    printf(\"Hello, World!\\n\");\n")
                f.write("    return 0;\n")
                f.write("}\n")
            print(f"Created main.c in {root}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <path>")
        sys.exit(1)
    
    path = sys.argv[1]
    if not os.path.isdir(path):
        print(f"Error: {path} is not a valid directory")
        sys.exit(1)
    
    create_main_c_if_not_exists(path)
    print("Script completed successfully")