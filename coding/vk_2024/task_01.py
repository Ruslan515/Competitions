from itertools import cycle


def xor(message, key):
    return bytes(a ^ b for a, b in zip(message, cycle(key)))


def text_from_bits(bits, encoding='utf-8', errors='surrogatepass'):
    n = int(bits, 2)
    return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode(encoding, errors) or '\0'


import string

alphabet_lower = string.ascii_lowercase  # "abcdefghijklmnopqrstuvwxyz"
alphabet_up = string.ascii_uppercase  # "abcdefghijklmnopqrstuvwxyz"


def decrypt(encrypted_message, key):
    # print("Welcome to Caesar Cipher Decryption.\n")
    # encrypted_message = input("Enter the message you would like to decrypt: ").strip()
    # print()
    # key = int(input("Enter key to decrypt: "))

    decrypted_message = ""

    for c in encrypted_message:
        if c in alphabet_lower:
            position = alphabet_lower.find(c)
            new_position = (position - key) % 26
            new_character = alphabet_lower[new_position]
            decrypted_message += new_character
        elif c in alphabet_up:
            position = alphabet_up.find(c)
            new_position = (position - key) % 26
            new_character = alphabet_up[new_position]
            decrypted_message += new_character
        else:
            decrypted_message += c

    print("\nDecrypting your message...\n")

    print("Stand by, almost finished...\n")

    print("Your decrypted message is:\n")
    print(decrypted_message)


def main():
    key = 0b111
    # key = bin(key)
    # phrase = b"1000001011110010110100001101111011100000110000100100000010110100110001001101000001000000111100001100010011011000111010001011000011000100110110000100000011000110111011001110011010000100111011101100001010010000111101000101001"
    # phrase = 0b1000001011110010110100001101111011100000110000100100000010110100110001001101000001000000111100001100010011011000111010001011000011000100110110000100000011000110111011001110011010000100111011101100001010010000111101000101001
    # y = phrase ^ key
    y = "1000001011110010110100001101111011100000110000100100000010110100110001001101000001000000111100001100010011011000111010001011000011000100110110000100000011000110111011001110011010000100111011101100001010010000111101000101110"
    # y = xor(phrase, key)

    txt = text_from_bits(y)
    decrypt(txt, key)




if __name__ == '__main__':
    main()
