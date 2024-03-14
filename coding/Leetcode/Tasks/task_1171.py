# https://leetcode.com/problems/winner-of-the-linked-list-game/?envType=weekly-question&envId=2024-03-01
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def remove_from_arr(self, arr: List[int]) -> bool:
        answer = True
        n = len(arr)
        for start in range(n):
            sums = 0
            label = False
            for end in range(start + 1, n + 1):
                sums = sum(arr[start: end])
                if sums == 0:
                    label = True
                    break
            if label:
                del arr[start: end]
                answer = False
                break
        return answer

    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        while head:
            arr.append(head.val)
            head = head.next

        while True:
            x = self.remove_from_arr(arr)
            if x:
                break
        prev = None
        for current in arr[::-1]:
            node = ListNode(current, prev)
            prev = node

        return prev


def main():
    solve = Solution()

    l1 = ListNode(-2)
    l2 = ListNode(-3, l1)
    l3 = ListNode(3, l2)
    l4 = ListNode(2, l3)
    l5 = ListNode(1, l4)
    head = l5

    solve.removeZeroSumSublists(head)


if __name__ == "__main__":
    main()
