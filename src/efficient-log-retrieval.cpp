#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void extract_logs(const string& log_file, const string& date) {
    string output_file = "output/output_" + date + ".txt";
    ifstream infile(log_file);
    ofstream outfile(output_file);
    
    if (!infile) {
        cerr << "Error: Unable to open log file!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        if (line.rfind(date, 0) == 0) { // Check if line starts with date
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();
    cout << "Logs for " << date << " saved in " << output_file << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./extract_logs YYYY-MM-DD" << endl;
        return 1;
    }

    string log_file = "logs.txt"; // Update with actual log file path
    extract_logs(log_file, argv[1]);

    return 0;
}