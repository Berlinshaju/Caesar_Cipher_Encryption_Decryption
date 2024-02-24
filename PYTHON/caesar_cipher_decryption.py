def caesar_decrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():  # Check if the character is a letter
            if char.isupper():  # Decrypt uppercase letters
                result += chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
            else:  # Decrypt lowercase letters
                result += chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
        else:
            result += char  # Keep non-letter characters unchanged
    return result

def main():
    ciphertext = input("Enter ciphertext: ")
    shift = int(input("Enter shift amount (1-25): "))

    # Decrypt the ciphertext using Caesar cipher
    plaintext = caesar_decrypt(ciphertext, shift)

    print("Decrypted text:", plaintext)

if __name__ == "__main__":
    main()
