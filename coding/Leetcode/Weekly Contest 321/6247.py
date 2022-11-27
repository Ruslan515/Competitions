# https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        current_node = head
        current_val = head.val
        # 241
        list_vals = []
        while current_node != None:
            current_val = current_node.val
            list_vals.append(current_val)
            current_node = current_node.next

        list_bin = []
        for i in range(len(list_vals) - 1):
            if max(list_vals[i + 1:]) > list_vals[i]:
                list_bin.append(0)
            else:
                list_bin.append(1)
        list_bin.append(1)

        idx_head = list_bin.index(1)
        for i in range(idx_head):
            head = head.next

        current_node = head
        for i in range(idx_head + 1, len(list_bin) - 1):
            e = list_bin[i]
            if e == 0:
                current_node.next = current_node.next.next
            else:
                current_node = current_node.next

        return head

def read_data():
    lists = list(map(int, input().split()))
    return lists


def main():
    lists = read_data()

    n = len(lists)
    list_node = [ListNode() for i in range(n)]
    for i in range(n - 1):
        list_node[i].val = lists[i]
        list_node[i].next = list_node[i + 1]
    list_node[n - 1].val = lists[n - 1]
    sol = Solution()

    head = sol.removeNodes(list_node[0])
    while head != None:
        print(head.val, end=" ")
        head = head.next
    print()

if __name__ == "__main__":
    main()