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

def decrypt_all_shifts(ciphertext):
    print("Decryption attempts for all 25 shifts:")
    for shift in range(1, 26):
        decrypted = caesar_decrypt(ciphertext, shift)
        print(f"Shift {shift}: {decrypted}")

def main():
    ciphertext = input("Enter ciphertext: ")
    decrypt_all_shifts(ciphertext)

if __name__ == "__main__":
    main()
