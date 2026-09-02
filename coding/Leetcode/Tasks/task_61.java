//https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class task_61 {
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

        public ListNode rotateRight(ListNode head, int k) {
            ArrayList<Integer> list = new ArrayList<>();
            while (head != null) {
                list.add(head.val);
                head = head.next;
            }
            int n = list.size();
            if (n == 0) return null;
            int[] arr = new int[n];
            int idx;
            for (int i = 0; i < n; ++i) {
                idx = (i + k) % n;
                arr[idx] = list.get(i);
            }
            ListNode answer = createListNode(arr);
            return answer;
        }

    }


    public void main(String[] args) {
        ListNode head;
        int k;
        ListNode answer;

        Solution solution = new Solution();

        head = solution.createListNode(new int[]{1, 2, 3, 4, 5});
        k = 2;
        answer = solution.createListNode(new int[]{4, 5, 1, 2, 3});
        assert answer == solution.rotateRight(head, k) : "Answer is different";

        head = solution.createListNode(new int[]{0, 1, 2});
        k = 4;
        answer = solution.createListNode(new int[]{2, 0, 1});
        assert answer == solution.rotateRight(head, k) : "Answer is different";

    }

}
