from typing import List


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        answer = []
        positive = []
        negative = []
        n = len(nums)
        for num in nums:
            if num > 0:
                positive.append(num)
            else:
                negative.append(num)
        for i in range(n):
            if i % 2 == 0:
                answer.append(positive[i // 2])
            else:
                answer.append(negative[i // 2])

        return answer


def main():
    solve = Solution()

    nums = [3, 1, -2, -5, 2, -4]
    answer = [3, -2, 1, -5, 2, -4]
    assert answer == solve.rearrangeArray(nums)

    nums = [-1, 1]
    answer = [1, -1]
    assert answer == solve.rearrangeArray(nums)


if __name__ == "__main__":
    main()
