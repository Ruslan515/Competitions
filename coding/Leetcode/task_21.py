# https://leetcode.com/problems/merge-two-sorted-lists/
from typing import List

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

def read_data():
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    intervals = [list(map(int, el.split(","))) for el in s]
    return intervals


def main():
    intervals = read_data()
    sol = Solution()
    print(sol.minGroups(intervals))

if __name__ == "__main__":
    main()