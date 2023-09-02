#include <stdio.h>
#include <string.h>

// Function to encrypt a message using the Caesar cipher
void encrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt a message using the Caesar cipher
void decrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}
