# https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        answer = 0
        queue = [root]
        while queue:
            size = len(queue)
            answer = queue[0].val
            for _ in range(size):
                node = queue.pop(0)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)

        return answer


def main():
    solve = Solution()

    t1 = TreeNode(7)
    t2 = TreeNode(5, t1)
    t3 = TreeNode(6)
    t4 = TreeNode(3, t2, t3)
    t5 = TreeNode(4)
    t6 = TreeNode(2, t5)
    t7 = TreeNode(1, t6, t4)
    answer = 7
    assert answer == solve.findBottomLeftValue(t7)

    t1 = TreeNode(1)
    t2 = TreeNode(3)
    t3 = TreeNode(2, t1, t2)
    answer = 1
    assert answer == solve.findBottomLeftValue(t3)



if __name__ == "__main__":
    main()
