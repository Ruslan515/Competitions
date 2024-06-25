from typing import List


class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        N = 5000
        answer = 0
        weight.sort()
        sums = 0
        for i, w in enumerate(weight):
            if (sums + weight[i]) <= N:
                sums += weight[i]
                answer += 1
            else:
                break

        return answer


def main():
    solve = Solution()

    weight = [100, 200, 150, 1000]
    answer = 4
    assert answer == solve.maxNumberOfApples(weight)

    weight = [900, 950, 800, 1000, 700, 800]
    answer = 5
    assert answer == solve.maxNumberOfApples(weight)


if __name__ == "__main__":
    main()
