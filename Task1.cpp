#include <iostream>

using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    char choice;
    
    do {
        cout << "Choose conversion type:\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Fahrenheit to Celsius\n";
        cout << "Enter your choice (1/2): ";
        cin >> choice;

        double temperature;

        switch (choice) {
            case '1':
                cout << "Enter temperature in Celsius: ";
                cin >> temperature;
                cout << "Equivalent temperature in Fahrenheit: " << celsiusToFahrenheit(temperature) << " F\n";
                break;

            case '2':
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temperature;
                cout << "Equivalent temperature in Celsius: " << fahrenheitToCelsius(temperature) << " C\n";
                break;

            default:
                cout << "Invalid choice. Please enter 1 or 2.\n";
        }

        cout << "Do you want to convert another temperature? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program. Thank you!\n";

    return 0;
}
