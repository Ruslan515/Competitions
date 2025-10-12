package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;

public class task_2815 {
    class Solution {
        private int getMaxDigit(int num) {
            // Более эффективная реализация
            int maxDigit = 0;
            while (num > 0) {
                int digit = num % 10;
                if (digit > maxDigit) {
                    maxDigit = digit;
                    if (maxDigit == 9) break; // Максимально возможная цифра
                }
                num /= 10;
            }
            return maxDigit;
        }

        public int maxSum(int[] nums) {
            int answer = -1;
            Map<Integer, Integer[]> map = new HashMap<>();
            int currVal;

            for (int i = 0; i < nums.length; ++i) {
                currVal = nums[i];
                int maxDigit = getMaxDigit(currVal);
                if (map.containsKey(maxDigit)) {
                    Integer[] currArr = map.get(maxDigit);
                    int maxVal = currArr[1];
                    int secondMaxVal = currArr[0];
                    if (currVal > maxVal) {
                        currArr[1] = currVal;
                        currArr[0] = maxVal;
                    } else if (currVal > secondMaxVal) {
                        currArr[0] = currVal;
                    }
                    map.put(maxDigit, currArr);
                    answer = Math.max(answer, currArr[0] + currArr[1]);
                } else {
                    map.put(maxDigit, new Integer[]{0, currVal});
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{84, 91, 18, 59, 27, 9, 81, 33, 17, 58};
        answer = 165;
        assert answer == solution.maxSum(nums) : "Answer is different";

        nums = new int[]{112, 131, 411};
        answer = -1;
        assert answer == solution.maxSum(nums) : "Answer is different";

        nums = new int[]{31, 25, 72, 79, 74};
        answer = 146;
        assert answer == solution.maxSum(nums) : "Answer is different";

        nums = new int[]{2536, 1613, 3366, 162};
        answer = 5902;
        assert answer == solution.maxSum(nums) : "Answer is different";

        nums = new int[]{51, 71, 17, 24, 42};
        answer = 88;
        assert answer == solution.maxSum(nums) : "Answer is different";
    }

}
