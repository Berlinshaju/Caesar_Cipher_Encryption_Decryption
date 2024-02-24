
#include <stdio.h>
#include <string.h>

void caesarDecrypt(char *text, int shift);

int main() {
    char ciphertext[100];

    // Input ciphertext
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Remove trailing newline if present
    if (ciphertext[strlen(ciphertext) - 1] == '\n')
        ciphertext[strlen(ciphertext) - 1] = '\0';

    printf("Decryption attempts for all 25 shifts:\n");

    // Try all 25 shifts and display decrypted text
    for (int shift = 1; shift <= 25; shift++) {
        char decrypted[100];
        strcpy(decrypted, ciphertext); // Copy ciphertext to decrypted string
        caesarDecrypt(decrypted, shift); // Decrypt with current shift
        printf("Shift %d: %s\n", shift, decrypted);
    }

    return 0;
}

void caesarDecrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        // Check if the character is a letter
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Decrypt uppercase letters
            text[i] = 'Z' - ('Z' - text[i] + shift) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            // Decrypt lowercase letters
            text[i] = 'z' - ('z' - text[i] + shift) % 26;
        }
    }
}
