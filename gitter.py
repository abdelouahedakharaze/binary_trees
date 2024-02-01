import os
import subprocess
import random
import time


def git_add_commit_push(file_path):
    # Stage the file
    subprocess.run(["git", "add", file_path])

    # Commit with the file name as the message
    commit_message = os.path.basename(file_path)
    subprocess.run(["git", "commit", "-m", commit_message])

    # Push changes
    subprocess.run(["git", "push"])


def get_unpushed_files(directory_path):
    # Get a list of all files in the directory
    files = [
        f
        for f in os.listdir(directory_path)
        if os.path.isfile(os.path.join(directory_path, f))
    ]

    # Check if there are unpushed files
    unpushed_files = []
    for file in files:
        file_path = os.path.join(directory_path, file)
        status = subprocess.run(
            ["git", "ls-files", "--error-unmatch", file_path], stderr=subprocess.PIPE
        )
        if status.returncode != 0:
            unpushed_files.append(file_path)

    return unpushed_files


def main(directory_path):
    while True:
        # Get a list of unpushed files
        unpushed_files = get_unpushed_files(directory_path)

        if not unpushed_files:
            print("All files have been pushed. Exiting.")
            break

        # Shuffle the list to randomize the order
        random.shuffle(unpushed_files)

        for file_path in unpushed_files:
            git_add_commit_push(file_path)
            print(f"Pushed: {os.path.basename(file_path)}")

            # Sleep for a random time between 5 and 10 minutes
            sleep_time = random.randint(100, 200)
            time.sleep(sleep_time)


if __name__ == "__main__":
    directory_path = "/Users/abdelouahedakharaze/alx-projects-all/binary_trees"  # Replace with the actual path to your directory
    main(directory_path)
