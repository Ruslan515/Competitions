# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """

        dx, dy = 1, 0
        x, y = 0, 0
        arr = [[-1] * n for _ in range(m)]
        for i in range(n * m):
            arr[x][y] = head[i]
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and not arr[nx][ny]:
                x, y = nx, ny
            else:
                dx, dy = -dy, dx
                x, y = x + dx, y + dy

        return arr

def read_data():
    m = int(input())
    n = int(input())
    head = list(map(int, input().replace("[", "").replace("]", "").split(",")))
    if (m * n) != len(head):
        to_add = [-1] * (m * n - len(head))
        head += to_add
    return m, n, head

def main():
    m, n, head = read_data()
    s = Solution()
    print(s.spiralMatrix(m, n, head))

if __name__ == "__main__":
    main()