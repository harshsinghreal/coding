#include <iostream>
#include <string>

using namespace std;

// Function to decrypt a single character using Vigenere cipher
char decryptChar(char cipherChar, char keyChar) {
    // Convert characters to uppercase
    cipherChar = toupper(cipherChar);
    keyChar = toupper(keyChar);

    // Perform Vigenere decryption
    char decryptedChar = 'A' + (cipherChar - keyChar + 26) % 26;

    return decryptedChar;
}

// Function to decrypt the entire ciphertext using Vigenere cipher
string decryptVigenere(const string& ciphertext, const string& key) {
    string decryptedText = "";
    int keyIndex = 0;

    for (char cipherChar : ciphertext) {
        // Skip non-alphabetic characters
        if (!isalpha(cipherChar)) {
            decryptedText += cipherChar;
            continue;
        }

        char keyChar = key[keyIndex % key.length()];

        decryptedText += decryptChar(cipherChar, keyChar);

        keyIndex++;
    }

    return decryptedText;
}

int main() {
    string ciphertext, key="yimqjhb";

    // Input ciphertext
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);

    // Input key
    cout << "Enter the key: ";
    getline(cin, key);

    // Decrypt the ciphertext using the Vigenere cipher
    string decryptedText = decryptVigenere(ciphertext, key);

    // Output the decrypted text
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
