#include <iostream>     // For input and output
#include <cstdlib>      // For system commands like system("cls")
#include <ctime>        // For seeding the random number generator
#include <random>       // For better random number generation
#include <Windows.h>    // For Sleep() function (Windows-specific)
#include <string>       // For using the string class

#define defaultDelay 30 // Default delay (in milliseconds) for text animation

using namespace std;

// Function to generate a random integer between lower_bound and upper_bound (inclusive)
// Uses <random> for better randomness compared to rand()
int random(int lower_bound, int upper_bound) {
    static random_device rd;             // Random seed
    static mt19937 gen(rd());            // Mersenne Twister engine
    uniform_int_distribution<> distrib(lower_bound, upper_bound); // Uniform distribution
    return distrib(gen);                 // Return a random number
}

// Function to print text with a typewriter-like animation
// Each character is printed with a delay in milliseconds
void coutAnimation(string text, int delay) {
    for (size_t i = 0; i < text.length(); i++) {
        cout << text[i];     // Print one character at a time
        cout.flush();        // Ensure it is displayed immediately
        Sleep(delay);        // Wait for 'delay' milliseconds
    }
    cout << endl;
}

int main() {
    int geld = 100;         // Player starts with 100 euros
    int einsatz, tipp, zufallszahl; // Variables for bet amount, guess, and drawn number

    // Welcome message
    coutAnimation("Willkommen zum Zahlenraten Spiel!\n", defaultDelay);

    // Main game loop: runs as long as the player has money
    while (geld > 0) {
        coutAnimation("Aktuelles Guthaben: " + to_string(geld) + " Euro\n", defaultDelay);
        coutAnimation("Wie viel willst du setzen? (0 = beenden): ", defaultDelay);
        cin >> einsatz;

        // Exit condition
        if (einsatz == 0) break;

        // Check for invalid bet amounts
        if (einsatz > geld || einsatz < 0) {
            coutAnimation("Ungueltiger Einsatz.", defaultDelay);
            continue; // Skip to next round
        }

        // Ask the player for their guess
        coutAnimation("Tipp eine Zahl zwischen 1 und 5: ", defaultDelay);
        cin >> tipp;

        // Check for invalid guesses
        if (tipp < 1 || tipp > 5) {
            coutAnimation("Ungueltige Zahl.", defaultDelay);
            continue; // Skip to next round
        }

        // Generate the winning number
        zufallszahl = random(1, 5);
        coutAnimation("Gezogene Zahl: " + to_string(zufallszahl) + "\n", defaultDelay);

        // Check if the player guessed correctly
        if (tipp == zufallszahl) {
            coutAnimation("Gewonnen! Du bekommst " + to_string(einsatz * 5) + " Euro.", defaultDelay);
            geld += einsatz * 4; // Player wins 4x bet amount + keeps original bet
        }
        else {
            coutAnimation("Verloren. Du verlierst " + to_string(einsatz) + " Euro.\n", defaultDelay);
            geld -= einsatz; // Subtract the bet from the total money
        }

        system("pause"); // Wait for user to press a key
        system("cls");   // Clear the screen (Windows-only)
    }

    // End of game message
    cout << "\nSpiel beendet. Endguthaben: " << geld << " Euro" << endl;
    return 0;
}
