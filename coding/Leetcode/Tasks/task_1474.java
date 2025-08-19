// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/?envType=weekly-question&envId=2025-05-29
package leetcode.tasks;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class task_1474 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode() {}
     * ListNode(int val) { this.val = val; }
     * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {
        public ListNode deleteNodes(ListNode head, int m, int n) {
            ListNode answer = head;
            ListNode current = head;
            ListNode prev;
            while (current != null) {
                prev = current;
                int i = 0;
                while (prev != null && i < (m - 1)) {
                    prev = prev.next;
                    ++i;
                }
                if (prev == null) {
                    break;
                }
                i = 0;
                current = prev.next;
                while (current != null && i < n) {
                    current = current.next;
                    ++i;
                }
                prev.next = current;
            }

            return answer;
        }
    }

    public ListNode read(int size) {
        ListNode prev = new ListNode(1);
        ListNode head = prev;
        for (int i = 1; i < size; i++) {
            ListNode curr = new ListNode(i + 1);
            prev.next = curr;
            prev = curr;
        }
        return head;
    }

    public void main(String[] args) {
        ListNode head;
        int m, n;
        ListNode answer;

        Solution solution = new Solution();

        int size = 11;
        head = read(size);
        m = 11;
        n = 3;
        answer = solution.deleteNodes(head, m, n);

    }
}
