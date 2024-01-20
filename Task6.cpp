#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random string for typing test
string generateRandomText(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string randomText;

    for (int i = 0; i < length; ++i) {
        randomText += characters[rand() % characters.length()];
    }

    return randomText;
}

// Function to perform typing test
void typingTest() {
    const int textLength = 50;  // Adjust the length of the text as needed
    string randomText = generateRandomText(textLength);
    string userInput;

    cout << "Typing Tester: Type the following text:\n";
    cout << randomText << "\n";

    auto start = chrono::high_resolution_clock::now();  // Start the timer

    cout << "Your typing: ";
    getline(cin, userInput);

    auto end = chrono::high_resolution_clock::now();  // Stop the timer

    // Calculate the time taken in seconds
    chrono::duration<double> duration = end - start;
    double timeTaken = duration.count();

    // Calculate accuracy
    int correctCharacters = 0;
    for (size_t i = 0; i < min(userInput.length(), randomText.length()); ++i) {
        if (userInput[i] == randomText[i]) {
            correctCharacters++;
        }
    }

    double accuracy = static_cast<double>(correctCharacters) / textLength * 100.0;

    // Display results
    cout << "\nTime taken: " << timeTaken << " seconds\n";
    cout << "Accuracy: " << accuracy << "%\n";
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Perform typing test
    typingTest();

    return 0;
}
