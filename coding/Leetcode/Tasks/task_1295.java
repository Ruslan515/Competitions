package leetcode.tasks;

public class task_1295 {
    class Solution {
        public int findNumbers(int[] nums) {
            int answer = 0;
            for (int num : nums) {
                String s = String.valueOf(num);
                if (s.length() % 2 == 0) {
                    ++answer;
                }
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        int[] nums;
        int x;
        int answer;

        Solution solution = new task_1295().new Solution();

        nums = new int[]{12, 345, 2, 6, 7896};
        answer = 2;
        x = solution.findNumbers(nums);
        assert answer == x : "Answer is different";

        nums = new int[]{555, 901, 482, 1771};
        answer = 1;
        x = solution.findNumbers(nums);
        assert answer == x : "Answer is different";

    }
}
