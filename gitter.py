import os
import subprocess
import random
import time


def is_git_repository():
    # Check if the current directory is a Git repository
    return (
        subprocess.run(
            ["git", "rev-parse", "--is-inside-work-tree"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        ).returncode
        == 0
    )


def git_add_commit_push(file_path):
    # Stage the file
    subprocess.run(["git", "add", file_path])

    # Commit with the file name as the message
    commit_message = os.path.basename(file_path)
    subprocess.run(["git", "commit", "-m", commit_message])

    # Push changes
    subprocess.run(["git", "push"])


def get_unpushed_files(directory_path, script_filename):
    # Get a list of all files in the directory
    files = [
        f
        for f in os.listdir(directory_path)
        if os.path.isfile(os.path.join(directory_path, f))
    ]

    # Check if there are unpushed files excluding the script file
    unpushed_files = []
    for file in files:
        file_path = os.path.join(directory_path, file)

        # Skip the script file
        if file == script_filename:
            continue

        status = subprocess.run(
            ["git", "ls-files", "--error-unmatch", file_path], stderr=subprocess.PIPE
        )
        if status.returncode != 0:
            unpushed_files.append(file_path)

    return unpushed_files


def main(directory_path):
    script_filename = os.path.basename(__file__)  # Get the name of the script file
    sleep_times = []

    # Check if the current directory is a Git repository
    if not is_git_repository():
        print("Error: This script must be run inside a Git repository.")
        return

    while True:
        # Get a list of unpushed files excluding the script file
        unpushed_files = get_unpushed_files(directory_path, script_filename)

        if not unpushed_files:
            print("All files have been pushed. Exiting.")
            break

        # Shuffle the list to randomize the order
        random.shuffle(unpushed_files)

        for file_path in unpushed_files:
            git_add_commit_push(file_path)
            print(f"Pushed: {os.path.basename(file_path)}")

            # Sleep for a random time between 5 and 10 minutes
            sleep_time = random.randint(100, 250)
            sleep_times.append(sleep_time)
            time.sleep(sleep_time)

    # Print sleep times and their total
    print("\nSleep times:")
    for i, sleep_time in enumerate(sleep_times, start=1):
        print(f"{i}. {sleep_time} seconds")

    total_sleep_time = sum(sleep_times)
    print(f"\nTotal sleep time: {total_sleep_time} seconds")


if __name__ == "__main__":
    directory_path = os.getcwd()  # Use the current working directory
    main(directory_path)
