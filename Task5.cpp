#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to simulate rolling a single die
int rollDie() {
    return rand() % 6 + 1; // Generates a random number between 1 and 6
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    char rollAgain;
    
    do {
        // Simulate rolling two dice
        int die1 = rollDie();
        int die2 = rollDie();

        // Print the results
        std::cout << "You rolled a " << die1 << " and a " << die2 << ". Total: " << die1 + die2 << std::endl;

        // Ask the user if they want to roll again
        std::cout << "Roll again? (y/n): ";
        std::cin >> rollAgain;
        
    } while (rollAgain == 'y' || rollAgain == 'Y');

    std::cout << "Thanks for playing the dice rolling simulator!" << std::endl;

    return 0;
}
