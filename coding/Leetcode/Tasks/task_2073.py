# https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08
from typing import List, Optional


class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        from collections import deque
        answer = 0
        dq = deque([(i, ticket) for i, ticket in enumerate(tickets)])
        while dq:
            answer += 1
            i, ticket = dq.popleft()
            ticket -= 1
            if i == k and ticket == 0:
                break
            if ticket != 0:
                dq.append((i, ticket))

        return answer


def main():
    solve = Solution()

    tickets = [2, 3, 2]
    k = 2
    answer = 6
    assert answer == solve.timeRequiredToBuy(tickets, k)

    tickets = [5, 1, 1, 1]
    k = 0
    answer = 8
    assert answer == solve.timeRequiredToBuy(tickets, k)


if __name__ == "__main__":
    main()
