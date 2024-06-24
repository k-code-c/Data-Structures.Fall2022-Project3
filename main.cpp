#include <iostream>
#include <string>
using namespace std;

int main() {
    char inputSize[80]; // Character array to store input with a size of 5000
    int inputLength = 0; // Length of current input
    char characters;
    int parenCount = 0; // To keep track of parentheses count

    while (true) {
        cout << "-> ";
        parenCount = 0; // Reset parentheses count for each input

        while (true) {
            characters = cin.get();

            if (characters == EOF) {
                break;
            } else if (characters == ';') {
                // Skip characters until the end of the line for comments
                while (characters != '\n' && characters != EOF) {
                    characters = cin.get();
                }
            } else if (characters == '(') {
                // Increase the parentheses count
                inputSize[inputLength++] = characters;
                parenCount++;
            } else if (characters == ')') {
                // Decrease the parentheses count
                inputSize[inputLength++] = characters;
                parenCount--;

                if (parenCount < 0) {
                    cout << ">" << endl; // Missing "(" detected
                    break;
                }
            } else if (characters == '\n') {
                if (parenCount > 0) {
                    cout << ">" << endl; // More "(" than ")"
                } else {
                    // The input is complete
                    inputSize[inputLength++] = '#'; // Special character to end the input
                    inputSize[inputLength] = '\0'; // Null-terminate the input
                    cout << inputSize << endl; // Print the input

                    // Reset for the next input
                    inputLength = 0;
                    break;
                }
            } else {
                // Store other characters in the input
                inputSize[inputLength++] = characters;
            }
        }

        // Check if the input is "quit" to terminate the program
        if (strcmp(inputSize, "quit") == 0) {
            break;
        }
    }

    cout << "The Program terminated." << endl;
    return 0;
}
