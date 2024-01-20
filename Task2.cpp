#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new file
void createFile(const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        cout << "File created successfully: " << fileName << endl;
        file.close();
    } else {
        cout << "Error creating file: " << fileName << endl;
    }
}

// Function to read the contents of a file
void readFile(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        cout << "Contents of file " << fileName << ":\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading: " << fileName << endl;
    }
}

// Function to update the contents of a file
void updateFile(const string& fileName, const string& newContent) {
    ofstream file(fileName, ios::app); // Open file in append mode
    if (file.is_open()) {
        file << newContent << endl;
        cout << "File updated successfully: " << fileName << endl;
        file.close();
    } else {
        cout << "Error opening file for updating: " << fileName << endl;
    }
}

// Function to delete a file
void deleteFile(const string& fileName) {
    if (remove(fileName.c_str()) == 0) {
        cout << "File deleted successfully: " << fileName << endl;
    } else {
        cout << "Error deleting file: " << fileName << endl;
    }
}

int main() {
    string fileName = "sample.txt";
    createFile(fileName);

    // Write some content to the file
    updateFile(fileName, "This is the first line.");
    updateFile(fileName, "This is the second line.");

    // Read and display the contents of the file
    readFile(fileName);

    // Update the file with additional content
    updateFile(fileName, "This is the third line.");

    // Read and display the updated contents of the file
    readFile(fileName);

    // Delete the file
    deleteFile(fileName);

    return 0;
}
