#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void rabinKarpSearch(string text, string pattern) {
    int textLength = text.length(); // Length of the text
    int patternLength = pattern.length(); // Length of the pattern
    int alphabetSize = 256; // Number of characters in the alphabet
    int prime = 101; // A prime number for hashing
    int hashFactor = 1; // Hash factor
    int patternHash = 0; // Hash value of the pattern
    int textHash = 0; // Hash value of the current substring of text

    // Calculate the hash factor
    for (int i = 0; i < patternLength - 1; i++)
        hashFactor = (hashFactor * alphabetSize) % prime;

    // Calculate the hash value of the pattern and the initial substring of text
    for (int i = 0; i < patternLength; i++) {
        patternHash = (alphabetSize * patternHash + pattern[i]) % prime;
        textHash = (alphabetSize * textHash + text[i]) % prime;
    }

    // Iterate through each possible position of the pattern in the text
    for (int i = 0; i <= textLength - patternLength; i++) {
        // Check if the hash values match
        if (patternHash == textHash) {
            // Perform character-by-character comparison to confirm the match
            int j;
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // If the pattern is found, print the index where it occurs in the text
            if (j == patternLength)
                cout << "Pattern found at index " << i << endl;
        }
        // Calculate the hash value of the next substring of text using a rolling hash update
        if (i < textLength - patternLength) {
            textHash = (alphabetSize * (textHash - text[i] * hashFactor) + text[i + patternLength]) % prime;
            // Adjust negative hash value
            if (textHash < 0)
                textHash += prime; 
        }
    }
}

int main() {
    int choice;
    cout << "1. From File\n2. From User\nEnter Choice: ";
    cin >> choice;
    cin.ignore(); 
    string text, pattern;
    if (choice == 1) {
        ifstream file("input.txt");
        if (!file.is_open()) {
            cout << "Error: Could not open file!" << endl;
            return 1;
        }
        getline(file, text);
        file.close();
    } 
    else {
        cout << "Enter Text: ";
        getline(cin, text);
    }
    cout << "Enter Pattern: ";
    getline(cin, pattern);
    rabinKarpSearch(text, pattern);
    return 0;
}
