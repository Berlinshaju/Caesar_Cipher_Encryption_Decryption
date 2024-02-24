def caesar_encrypt(text, shift):
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
    print("Encryption attempts for all 25 shifts:")
    for shift in range(1, 26):
        encrypted = caesar_encrypt(plaintext, shift)
        print(f"Shift {shift}: {encrypted}")

if __name__ == "__main__":
    main()
