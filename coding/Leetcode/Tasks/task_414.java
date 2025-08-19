package leetcode.tasks;

import java.util.ArrayList;
import java.util.List;

public class task_414 {
    class Solution {
        public int thirdMax(int[] nums) {
            int answer = Integer.MIN_VALUE - 1;
            long m1 = Long.MIN_VALUE, m2 = Long.MIN_VALUE, m3 = Long.MIN_VALUE;
            for (int num : nums) {
                if (num > m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = num;
                } else if (num > m2 && num != m1) {
                    m3 = m2;
                    m2 = num;
                } else if (num > m3 && num != m2 && num != m1) {
                    m3 = num;
                }
            }
            if (m3 == Long.MIN_VALUE) {
                answer = (int) m1;
            } else {
                answer = (int) m3;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{1, 2, -2147483648};
        answer = -2147483648;
        assert answer == solution.thirdMax(nums) : "Answer is different";

        nums = new int[]{1, 2, 2, 5, 3, 5};
        answer = 2;
        assert answer == solution.thirdMax(nums) : "Answer is different";

        nums = new int[]{2, 2, 3, 1};
        answer = 1;
        assert answer == solution.thirdMax(nums) : "Answer is different";

        nums = new int[]{3, 2, 1};
        answer = 1;
        assert answer == solution.thirdMax(nums) : "Answer is different";

        nums = new int[]{1, 2};
        answer = 2;
        assert answer == solution.thirdMax(nums) : "Answer is different";

    }

}
