#!/bin/bash

# Check if a problem folder path is provided
if [ $# -eq 0 ]; then
    echo "Please provide the path to the problem folder."
    exit 1
fi

PROBLEM_FOLDER=$1
CURRENT_DIR=$(pwd)

# Change to the problem folder
cd "$PROBLEM_FOLDER" || exit

# Compile Unity
gcc -c unity.c -o unity.o
if [ $? -ne 0 ]; then
    echo "Compilation of Unity failed."
    exit 1
fi

# Compile the code with coverage flags
gcc -fprofile-arcs -ftest-coverage -c code.c -o code.o
if [ $? -ne 0 ]; then
    echo "Compilation of code.c failed."
    exit 1
fi

# Compile the test code with coverage flags
gcc -fprofile-arcs -ftest-coverage -c main.c -o main.o
if [ $? -ne 0 ]; then
    echo "Compilation of main.c failed."
    exit 1
fi

# Link the object files
gcc -fprofile-arcs -ftest-coverage code.o main.o unity.o -o test_program -lm
if [ $? -ne 0 ]; then
    echo "Linking failed."
    exit 1
fi

# Run the tests
./test_program
if [ $? -ne 0 ]; then
    echo "Tests failed."
    exit 1
fi

# Generate coverage information
gcov code.c

# Display coverage summary
gcov -b code.c

# Move coverage report to parent directory
mkdir -p "$CURRENT_DIR/coverage_report_$(basename "$PROBLEM_FOLDER")"
mv *.gcov "$CURRENT_DIR/coverage_report_$(basename "$PROBLEM_FOLDER")/"

# Clean up
rm -f *.o test_program *.gcda *.gcno

# Change back to the original directory
cd "$CURRENT_DIR" || exit

echo "Testing and coverage analysis completed. Coverage report is available in coverage_report_$(basename "$PROBLEM_FOLDER")"