class Solution(object):
    def decodeMessage(self, key, message):
        """
        :type key: str
        :type message: str
        :rtype: str
        """
        alphabet = list(map(chr,range(ord('a'),ord('z')+1)))
        my_dict = {}
        idx = 0
        for letter in key.replace(" ", ""):
            if letter not in my_dict.keys():
                my_dict[letter] = alphabet[idx]
                idx += 1
        my_dict[" "] = " "
        decode_message = [my_dict[ch] for ch in message]
        decode_message = "".join(decode_message)

        return decode_message

def read_data():
    key = input()
    message = input()
    return key, message

def main():
    key, message = read_data()
    s = Solution()
    print(s.decodeMessage(key, message))

if __name__ == "__main__":
    main()