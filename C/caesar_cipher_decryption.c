#include <stdio.h>
#include <string.h>

void caesarDecrypt(char *text, int shift);

int main() {
    char ciphertext[100];
    int shift;

    // Input ciphertext
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Remove trailing newline if present
    if (ciphertext[strlen(ciphertext) - 1] == '\n')
        ciphertext[strlen(ciphertext) - 1] = '\0';

    // Input shift amount
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // Decrypt the ciphertext using Caesar cipher
    caesarDecrypt(ciphertext, shift);

    printf("Decrypted text: %s\n", ciphertext);

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

