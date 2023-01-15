# Definition for a binary tree node.
from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def down(self, root):
        head = root
        left = root.left
        right = root.right
        while left.left != None:
            self.down(left)
        head.left = None
        print(head.val, left.val)
        while right.right != None:
            self.down(right)
        head.right = None
        print(head.val, right.val)

        return

    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.down(root)
        return


if __name__ == "__main__":
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.left.left = TreeNode(4)
    tree.left.right = TreeNode(5)
    s = Solution()
    s.findLeaves(tree)