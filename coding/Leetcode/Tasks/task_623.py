# https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            new_root = TreeNode(val, left=root)
            return new_root
        from collections import deque
        dq = deque()
        dq.append(root)
        i = 1
        answer = root
        while dq:
            if i == depth - 1:
                size_q = len(dq)
                for _ in range(size_q):
                    node = dq.popleft()
                    if node.left:
                        t = TreeNode(val, left=node.left)
                        node.left = t
                    else:
                        t = TreeNode(val)
                        node.left = t
                    if node.right:
                        t = TreeNode(val, right=node.right)
                        node.right = t
                    else:
                        t = TreeNode(val)
                        node.right = t
                break
            else:
                size_q = len(dq)
                for _ in range(size_q):
                    node = dq.popleft()
                    if node.left:
                        dq.append(node.left)
                    if node.right:
                        dq.append(node.right)
            i += 1

        return answer


def main():
    solve = Solution()

    t1 = TreeNode(4)
    t2 = TreeNode(2, t1)
    t3 = TreeNode(3)
    t4 = TreeNode(1, t2, t3)

    root = t4
    val = 5
    depth = 4
    solve.addOneRow(root, val, depth)


    t1 = TreeNode(3)
    t2 = TreeNode(1)
    t3 = TreeNode(2, t1, t2)
    t6 = TreeNode(4, t3)

    root = t6
    val = 1
    depth = 3
    solve.addOneRow(root, val, depth)

    t1 = TreeNode(3)
    t2 = TreeNode(1)
    t3 = TreeNode(2, t1, t2)
    t4 = TreeNode(5)
    t5 = TreeNode(6, t4)
    t6 = TreeNode(4, t3, t5)

    root = t6
    val = 1
    depth = 2
    solve.addOneRow(root, val, depth)


if __name__ == "__main__":
    main()
