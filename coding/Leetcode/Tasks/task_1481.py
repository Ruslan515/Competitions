# https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
from typing import List


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        answer = 0
        mp = dict()
        for num in arr:
            mp[num] = mp.get(num, 0) + 1
        mp = dict(sorted(mp.items(), key=lambda x: x[1]))
        for key, value in mp.items():
            if value <= k:
                mp[key] = 0
                k -= value
            if k == 0:
                break

        for key in list(mp.keys()):
            if mp[key] == 0:
                del mp[key]
        answer = len(mp)

        return answer


def main():
    solve = Solution()

    arr = [2, 1, 1, 3, 3, 3]
    k = 3
    answer = 1
    assert answer == solve.findLeastNumOfUniqueInts(arr, k)

    arr = [4, 3, 1, 1, 3, 3, 2]
    k = 3
    answer = 2
    assert answer == solve.findLeastNumOfUniqueInts(arr, k)

    arr = [5, 5, 4]
    k = 1
    answer = 1
    assert answer == solve.findLeastNumOfUniqueInts(arr, k)


if __name__ == "__main__":
    main()
