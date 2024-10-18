import os
import shutil

def copy_to_subfolders(file_path, main_folder):
    # Check if the file and main folder exist
    if not os.path.isfile(file_path):
        print(f"Error: The file {file_path} does not exist.")
        return
    if not os.path.isdir(main_folder):
        print(f"Error: The folder {main_folder} does not exist.")
        return

    # Get the filename from the file path
    file_name = os.path.basename(file_path)

    # Walk through all subfolders in the main folder
    for root, dirs, files in os.walk(main_folder):
        # Skip the 'problem1' folder
        if os.path.basename(root) == 'problem1':
            continue
        
        # Copy the file to the current subfolder
        if root != main_folder:  # Skip the main folder itself
            destination = os.path.join(root, file_name)
            try:
                shutil.copy2(file_path, destination)
                print(f"Copied {file_name} to {root}")
            except Exception as e:
                print(f"Error copying to {root}: {str(e)}")

if __name__ == "__main__":
    # Specify your file path and main folder path here
    file_path = "/l/users/chaimaa.abi/NeXt/assembly_project/eval/problem1/unity_internals.h"
    main_folder = "/l/users/chaimaa.abi/NeXt/assembly_project/eval"
    
    copy_to_subfolders(file_path, main_folder)