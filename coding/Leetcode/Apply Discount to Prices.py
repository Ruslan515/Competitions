# https://leetcode.com/contest/weekly-contest-295/problems/apply-discount-to-prices/

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        import re
        pattern = r"\$[0-9]+"
        list_words = sentence.split()
        ans = []
        for word in list_words:
            if re.fullmatch(pattern, word):
                price = int(word[1:])
                new_price = price - price * discount / 100
                word = f"${new_price:0.2f}"
            ans.append(word)
        result = " ".join(ans)
        return result

def read_data():
    sentence = input()
    discount = int(input())
    return sentence, discount


def main():
    sentence, discount = read_data()
    s = Solution()
    print(s.discountPrices(sentence, discount))

if __name__ == "__main__":
    main()