# https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

from typing import List, Optional
import queue
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        answer: bool = True
        q = deque()
        q.append(root)
        i = 0
        while q:
            size: int = len(q)
            d = 0
            prev = 1_000_001
            if i % 2 == 0:
                d = 1
                prev = -1

            for _ in range(size):
                node = q.popleft()
                val = node.val
                if d:  # even index
                    x = val > prev
                    if x:
                        y = (val % 2) == d
                        if not y:
                            answer = False
                            return answer
                    else:
                        answer = False
                        return answer

                else:  # odd index
                    x = val < prev
                    if x:
                        y = (val % 2) == d
                        if not y:
                            answer = False
                            return answer
                    else:
                        answer = False
                        return answer

                prev = val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            i += 1

        return answer


def main():
    solve = Solution()

    t1 = TreeNode(3)
    t2 = TreeNode(3)
    t3 = TreeNode(4, t1, t2)
    t4 = TreeNode(7)
    t5 = TreeNode(2, t4)
    t6 = TreeNode(5, t3, t5)
    root = t6
    answer = False
    assert answer == solve.isEvenOddTree(root)

    t1 = TreeNode(12)
    t2 = TreeNode(8)
    t3 = TreeNode(3, t1, t2)
    t4 = TreeNode(10, t3)
    t5 = TreeNode(6)
    t6 = TreeNode(7, t5)
    t7 = TreeNode(2)
    t8 = TreeNode(9, right=t7)
    t9 = TreeNode(4, t6, t8)
    t10 = TreeNode(1, t4, t9)
    root = t10
    answer = True
    assert answer == solve.isEvenOddTree(root)


if __name__ == "__main__":
    main()
