# https://leetcode.com/problems/linked-list-frequency/description/?envType=weekly-question&envId=2024-03-08
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dict_freq = {}
        while head:
            dict_freq[head.val] = dict_freq.get(head.val, 0) + 1
            head = head.next
        prev = None
        for key, val in dict_freq.items():
            l_i = ListNode(val, prev)
            prev = l_i
        return prev


def main():
    solve = Solution()

    l1 = ListNode(2)
    l2 = ListNode(2, l1)
    l3 = ListNode(2, l2)
    l4 = ListNode(1, l3)
    l5 = ListNode(1, l4)
    head = l5
    solve.frequenciesOfElements(head)


    l1 = ListNode(3)
    l2 = ListNode(2, l1)
    l3 = ListNode(1, l2)
    l4 = ListNode(2, l3)
    l5 = ListNode(1, l4)
    l6 = ListNode(1, l5)
    head = l6
    solve.frequenciesOfElements(head)


if __name__ == "__main__":
    main()
