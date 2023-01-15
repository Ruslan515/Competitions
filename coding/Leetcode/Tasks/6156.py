# https://leetcode.com/contest/biweekly-contest-85/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        target = "B" * k
        if target in blocks:
            return 0
        from collections import Counter
        min_cnt = k
        for i in range(len(blocks) - k + 1):
            slice = blocks[i: i + k]
            c = Counter(slice)
            if c["W"] < min_cnt:
                min_cnt = c["W"]

        return min_cnt

def read_data():
    k = int(input())
    blocks= input()
    return k, blocks


def main():
    k, blocks = read_data()
    s = Solution()
    print(s.minimumRecolors(blocks, k))

if __name__ == "__main__":
    main()