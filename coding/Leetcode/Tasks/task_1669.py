# https://leetcode.com/problems/merge-in-between-linked-lists/?envType=daily-question&envId=2024-03-20
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        start = list1
        for i in range(a - 1):
            start = start.next
        end = start
        for i in range(b - a + 2):
            end = end.next

        end2 = list2
        while end2.next:
            end2 = end2.next
        start.next = list2
        end2.next = end
        return list1

def main():
    solve = Solution()

    l1 = ListNode(5)
    l2 = ListNode(9, l1)
    l3 = ListNode(6, l2)
    l4 = ListNode(13, l3)
    l5 = ListNode(1, l4)
    l6 = ListNode(10, l5)
    list1 = l6
    a = 3
    b = 4
    l7 = ListNode(1000002)
    l8 = ListNode(1000001, l7)
    l9 = ListNode(1000000, l8)
    list2 = l9
    solve.mergeInBetween(list1, a, b, list2)


if __name__ == "__main__":
    main()
