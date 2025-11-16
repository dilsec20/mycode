#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));
    
    int number = rand() % 9 + 1;  // Random number between 1 and 9
    int guess;
    int tries = 5;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess a number between 1 and 9. You have 5 tries.\n";

    for (int i = 1; i <= tries; i++) {
        cout << "Attempt " << i << ": ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the correct number " << number << "!\n";
            return 0; // Exit the program
        } else {
            if (i != tries)
                cout << "Wrong guess. Try again.\n";
        }
    }

    // If all attempts are used
    cout << "Sorry, you've used all your attempts. The correct number was " << number << ".\n";

    return 0;
}
