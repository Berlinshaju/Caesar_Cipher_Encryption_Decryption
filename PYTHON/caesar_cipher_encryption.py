def caesar_cipher(text, shift):
    result = ""
    for char in text:
        if char.isalpha():  # Check if the character is a letter
            if char.isupper():  # Encrypt uppercase letters
                result += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
            else:  # Encrypt lowercase letters
                result += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
        else:
            result += char  # Keep non-letter characters unchanged
    return result

def main():
    plaintext = input("Enter plaintext: ")
    shift = int(input("Enter shift amount (1-25): "))

    # Encrypt the plaintext using Caesar cipher
    ciphertext = caesar_cipher(plaintext, shift)

    print("Cipher text:", ciphertext)

if __name__ == "__main__":
    main()
