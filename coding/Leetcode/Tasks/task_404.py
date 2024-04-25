# https://leetcode.com/problems/sum-of-left-leaves/?envType=daily-question&envId=2024-04-14
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        from collections import deque
        answer = 0

        dq = deque()
        dq.append(root)
        while dq:
            size_q = len(dq)
            for _ in range(size_q):
                node = dq.popleft()
                if node.left:
                    if node.left.left is None and node.left.right is None:
                        val = node.left.val
                        answer += val
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

        return answer


def main():
    solve = Solution()

    solve.sumOfLeftLeaves(num, k)


if __name__ == "__main__":
    main()
