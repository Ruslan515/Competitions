// https://leetcode.com/problems/first-unique-number/description/?envType=weekly-question&envId=2025-05-22
package leetcode.tasks;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class task_1429 {
    class FirstUnique {
        private HashMap<Integer, Integer> freq;
        private Queue<Integer> queue;

        public FirstUnique(int[] nums) {
            freq = new HashMap<>();
            for (int num : nums) {
                freq.put(num, freq.getOrDefault(num, 0) + 1);
            }
            queue = new LinkedList<>();
            for (int num : nums) {
                queue.add(num);
            }

        }

        public int showFirstUnique() {
            int answer = -1;
            Integer num;
            Integer cnt;
            while (!queue.isEmpty()) {
                num = queue.element();
                cnt = freq.get(num);
                if (cnt == 1) {
                    answer = num;
                    break;
                }
                queue.remove();
            }

            return answer;
        }

        public void add(int value) {
            freq.put(value, freq.getOrDefault(value, 0) + 1);
            queue.add(value);
        }
    }

    public void main(String[] args) {
        int[] nums;

        nums = new int[]{2, 3, 5};
        FirstUnique firstUnique = new FirstUnique(nums);
        assert 2 == firstUnique.showFirstUnique() : "Answer is different";
        firstUnique.add(5);            // the queue is now [2,3,5,5]
        assert 2 == firstUnique.showFirstUnique(); // return 2
        firstUnique.add(2);            // the queue is now [2,3,5,5,2]
        assert 3 == firstUnique.showFirstUnique(); // return 3
        firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
        assert -1 == firstUnique.showFirstUnique(); // return -1

        nums = new int[]{7, 7, 7, 7, 7, 7};
        firstUnique = new FirstUnique(nums);
        assert -1 == firstUnique.showFirstUnique() : "Answer is different";
        firstUnique.add(3);            // the queue is now [2,3,5,5]
        assert 3 == firstUnique.showFirstUnique(); // return 2
        firstUnique.add(3);            // the queue is now [2,3,5,5,2]
        assert -1 == firstUnique.showFirstUnique(); // return 3
        firstUnique.add(7);            // the queue is now [2,3,5,5,2,3]
        assert -1 == firstUnique.showFirstUnique(); // return -1
        firstUnique.add(17);            // the queue is now [2,3,5,5,2,3]
        assert 17 == firstUnique.showFirstUnique(); // return -1

        nums = new int[]{809};
        firstUnique = new FirstUnique(nums);
        assert 809 == firstUnique.showFirstUnique() : "Answer is different";
        firstUnique.add(809);            // the queue is now [2,3,5,5]
        assert -1 == firstUnique.showFirstUnique(); // return 2

    }
}
