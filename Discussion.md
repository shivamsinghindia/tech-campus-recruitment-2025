Given the problem constraints (1 TB log file), an efficient approach is required for extracting logs of a specific date. Here are the approaches explored:

1️⃣ Brute Force Approach (Line-by-Line Parsing)
	•	Approach: Read the entire file line by line, check if the line starts with the target date, and store matching lines in an output file.
	•	Time Complexity: O(N) (where N is the number of lines in the file)
	•	Space Complexity: O(1) (excluding file I/O)
	•	Issues: This approach is slow because reading a 1 TB file sequentially takes a lot of time.

2️⃣ Index-Based Approach (Preprocessing the File)
	•	Approach: Preprocess the log file and create an index file that stores byte offsets for each day. When searching for logs, directly seek to the offset and read only the relevant portion.
	•	Time Complexity: O(1) for retrieval (assuming an indexed log file)
	•	Space Complexity: O(D) (where D is the number of distinct dates in the file)
	•	Issues: Requires a preprocessing step that may not be feasible in a competitive coding setting.

3️⃣ Efficient Streaming Approach (Final Solution Chosen ✅)
	•	Approach:
	•	Open the log file in streaming mode (read in chunks instead of loading the full file).
	•	Read line-by-line and directly write matching lines to the output file.
	•	Uses buffered file reading for efficiency.
	•	Time Complexity: O(N) (but optimized with buffered reading).
	•	Space Complexity: O(1) (since only a few lines are stored in memory at a time).
	•	Why Chosen? ✅
	•	Works without pre-processing.
	•	Handles large files efficiently by avoiding excessive memory usage.
	•	Simple and effective for real-world log file parsing.
     Final Solution Summary

The final solution uses buffered reading with an efficient file streaming approach:
	•	Reads logs line by line instead of loading the full file.
	•	Uses a substring match to find logs of the requested date.
	•	Writes only relevant lines to the output file to minimize memory usage.
	•	Works efficiently even for large files (~1 TB).
    🔹 Steps to Run the Solution in C++

📌 Prerequisites
	•	C++ Compiler (g++ for Linux/macOS, MinGW for Windows).
	•	Log file (logs.txt) containing the logs.
    📌 Compilation & Execution Steps

Step 1: Compile the C++ Program

Run the following command in the terminal:
g++ extract_logs.cpp -o extract_logs
This compiles the program into an executable named extract_logs.

Step 2: Run the Program with a Date Argument

Execute the program with the target date as an argument:
./extract_logs 2024-12-01
extract_logs.exe 2024-12-01
output/output_2024-12-01.txt
cat output/output_2024-12-01.txt
./extract_logs 2024-12-01
