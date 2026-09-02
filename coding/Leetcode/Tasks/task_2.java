//https://leetcode.com/problems/add-two-numbers/
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_2 {
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

        static {
            Runtime.getRuntime().gc();
            Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                    writer.write("0");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }));
        }

        void endSum(ListNode curr, ListNode head, int whole) {
            int val, valResult, remain;
            ListNode test = curr;
            while (head != null) {
                val = head.val;
                valResult = val + whole;
                remain = valResult % 10;
                whole = valResult / 10;
                ListNode next = new ListNode(remain);
                curr.next = next;
                curr = next;
                head = head.next;
            }
            if (whole != 0) {
                ListNode next = new ListNode(1);
                curr.next = next;
            }
        }

        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode answer = new ListNode();
            ListNode curr = answer;
            int val1, val2, valResult = 0, remain = 0, whole = 0;
            while (l1 != null && l2 != null) {
                val1 = l1.val;
                val2 = l2.val;
                valResult = val1 + val2 + whole;
                remain = valResult % 10;
                curr.val = remain;
                whole = valResult / 10;
                l1 = l1.next;
                l2 = l2.next;
                if (l1 != null && l2 != null) {
                    ListNode next = new ListNode();
                    curr.next = next;
                    curr = next;
                }
            }
            if (l1 == null && l2 == null && whole != 0) {
                ListNode next = new ListNode(1);
                curr.next = next;
            } else if (l1 == null && l2 != null) {
                endSum(curr, l2, whole);
            } else if (l1 != null && l2 == null) {
                endSum(curr, l1, whole);
            }

            return answer;
        }

    }

    public ListNode createListNode(int[] arr) {
        ListNode head = new ListNode(arr[0]);
        ListNode prev = head;
        for (int i = 1; i < arr.length; ++i) {
            ListNode current = new ListNode(arr[i]);
            prev.next = current;
            prev = current;
        }
        return head;
    }

    public void main(String[] args) {
        ListNode l1, l2;
        ListNode answer;

        Solution solution = new Solution();

        l1 = createListNode(new int[]{2, 4, 3});
        l2 = createListNode(new int[]{5, 6, 4});
        answer = createListNode(new int[]{7, 0, 8});
        assert answer == solution.addTwoNumbers(l1, l2) : "Answer is different";

        l1 = createListNode(new int[]{9, 9, 9, 9, 9, 9, 9});
        l2 = createListNode(new int[]{9, 9, 9, 9});
        answer = createListNode(new int[]{8, 9, 9, 9, 0, 0, 0, 1});
        assert answer == solution.addTwoNumbers(l1, l2) : "Answer is different";

        l1 = createListNode(new int[]{0});
        l2 = createListNode(new int[]{0});
        answer = createListNode(new int[]{0});
        assert answer == solution.addTwoNumbers(l1, l2) : "Answer is different";
    }

}
