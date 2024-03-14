# https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next is None:
            return None
        first = head.next
        second = head

        for _ in range(n - 1):
            first = first.next
        if first is None:
            head = second.next
            return head
        while first.next:
            first = first.next
            second = second.next
        second.next = second.next.next

        return head


def main():
    solve = Solution()

    l1 = ListNode(5)
    l2 = ListNode(4, l1)
    l3 = ListNode(3, l2)
    l4 = ListNode(2, l3)
    l5 = ListNode(1, l4)
    head = l5
    n = 2
    assert head == solve.removeNthFromEnd(head, n)

    l1 = ListNode(2)
    l2 = ListNode(1, l1)
    head = l2
    n = 2
    assert None == solve.removeNthFromEnd(head, n)

    l1 = ListNode(1)
    head = l1
    n = 1
    assert None == solve.removeNthFromEnd(head, n)


if __name__ == "__main__":
    main()
