# https://leetcode.com/problems/winner-of-the-linked-list-game/?envType=weekly-question&envId=2024-03-01
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        answer: str = "Tie"
        count = 0
        while head:
            val_even = head.val
            val_odd = head.next.val
            if val_even > val_odd:
                count += 1
            elif val_odd > val_even:
                count -= 1
            head = head.next.next
        if count > 0:
            answer = "Even"
        elif count < 0:
            answer = "Odd"

        return answer


def main():
    solve = Solution()

    l1 = ListNode(1)
    l2 = ListNode(2, l1)
    l3 = ListNode(5, l2)
    l4 = ListNode(4, l3)
    head = l4
    answer = "Tie"
    assert answer == solve.gameResult(head)


    l1 = ListNode(1)
    l2 = ListNode(2, l1)
    head = l2
    answer = "Even"
    assert answer == solve.gameResult(head)

    head = [2, 5, 4, 7, 20, 5]
    l1 = ListNode(5)
    l2 = ListNode(20, l1)
    l3 = ListNode(7, l2)
    l4 = ListNode(4, l3)
    l5 = ListNode(5, l4)
    l6 = ListNode(2, l5)
    head = l6
    answer = "Odd"
    assert answer == solve.gameResult(head)



if __name__ == "__main__":
    main()
