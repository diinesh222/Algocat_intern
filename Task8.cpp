#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to convert date format
string convertDateFormat(const string& inputDate, const string& inputFormat, const string& outputFormat) {
    stringstream ss(inputDate);
    int day, month, year;

    if (inputFormat == "DD/MM/YYYY" || inputFormat == "MM/DD/YYYY" || inputFormat == "YYYY/MM/DD") {
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
    } else {
        cout << "Invalid input date format!" << endl;
        return "";
    }

    if (outputFormat == "DD/MM/YYYY" || outputFormat == "MM/DD/YYYY" || outputFormat == "YYYY/MM/DD") {
        stringstream outputSS;
        if (outputFormat == "DD/MM/YYYY") {
            outputSS << setfill('0') << setw(2) << day << '/' << setfill('0') << setw(2) << month << '/' << year;
        } else if (outputFormat == "MM/DD/YYYY") {
            outputSS << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day << '/' << year;
        } else if (outputFormat == "YYYY/MM/DD") {
            outputSS << year << '/' << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day;
        }
        return outputSS.str();
    } else {
        cout << "Invalid output date format!" << endl;
        return "";
    }
}

int main() {
    string inputDate, inputFormat, outputFormat;

    cout << "Enter the date (format: DD/MM/YYYY, MM/DD/YYYY, or YYYY/MM/DD): ";
    getline(cin, inputDate);

    cout << "Enter the input date format: ";
    cin >> inputFormat;

    cout << "Enter the output date format: ";
    cin >> outputFormat;

    string convertedDate = convertDateFormat(inputDate, inputFormat, outputFormat);

    if (!convertedDate.empty()) {
        cout << "Converted date: " << convertedDate << endl;
    }

    return 0;
}
