#include <stdio.h>
#include <string.h>

void caesarCipher(char *text, int shift);

int main() {
    char plaintext[100];
    int shift;

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove trailing newline if present
    if (plaintext[strlen(plaintext) - 1] == '\n')
        plaintext[strlen(plaintext) - 1] = '\0';

    // Input shift amount
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // Encrypt the plaintext using Caesar cipher
    caesarCipher(plaintext, shift);

    printf("Cipher text: %s\n", plaintext);

    return 0;
}

void caesarCipher(char *text, int shift) {
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

