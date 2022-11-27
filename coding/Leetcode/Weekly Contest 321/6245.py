# https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

class Solution:
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        answer = -1

        import numpy as np
        arr = np.array([i for i in range(1, n + 1)])

        if n == 1:
            answer = 1
        else:
            for i in range(n, n //2, -1):
                idx = i
                sum_left = arr[:idx].sum()
                sum_right = arr[idx - 1:].sum()
                if sum_left == sum_right:
                    answer = i
                    break

        return answer


def read_data():
    n = int(input())
    return n


def main():
    n = read_data()
    sol = Solution()
    print(sol.pivotInteger(n))

if __name__ == "__main__":
    main()