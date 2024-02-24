#include <stdio.h>
#include <string.h>

void caesarEncrypt(char *text, int shift);

int main() {
    char plaintext[100];

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove trailing newline if present
    if (plaintext[strlen(plaintext) - 1] == '\n')
        plaintext[strlen(plaintext) - 1] = '\0';

    printf("Encryption attempts for all 25 shifts:\n");

    // Try all 25 shifts and display encrypted text
    for (int shift = 1; shift <= 25; shift++) {
        char encrypted[100];
        strcpy(encrypted, plaintext); // Copy plaintext to encrypted string
        caesarEncrypt(encrypted, shift); // Encrypt with current shift
        printf("Shift %d: %s\n", shift, encrypted);
    }

    return 0;
}

void caesarEncrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        // Check if the character is a letter
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Encrypt uppercase letters
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            // Encrypt lowercase letters
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        }
    }
}

