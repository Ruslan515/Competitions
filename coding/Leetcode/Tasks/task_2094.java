package leetcode.tasks;

import java.util.Arrays;
import java.util.HashSet;

public class task_2094 {
    class Solution {
        public int[] findEvenNumbers(int[] digits) {
            int n = digits.length;
            int x1, x2, x3;
            HashSet<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        x1 = digits[i];
                        x2 = digits[j];
                        x3 = digits[k];
                        int[] arr = {x1, x2, x3};
                        for (int idx1 = 0; idx1 < arr.length; idx1++) {
                            for (int idx2 = 0; idx2 < arr.length; idx2++) {
                                for (int idx3 = 0; idx3 < arr.length; idx3++) {
                                    if (idx1 != idx2 && idx2 != idx3 && idx3 != idx1) {
                                        x1 = arr[idx1];
                                        x2 = arr[idx2];
                                        x3 = arr[idx3];
                                        if (x1 != 0 && x3 % 2 == 0) {
                                            set.add(x1 * 100 + x2 * 10 + x3);
                                        }

                                    }
                                }
                            }
                        }

                    }
                }
            }
            int[] answer = new int[set.size()];
            int i = 0;
            for (Integer item : set) {
                answer[i] = item;
                ++i;
            }
            Arrays.sort(answer);
            return answer;
        }
    }

    public static void main(String[] args) {
        int[] digits;
        int[] x;
        int[] answer;

        Solution solution = new task_2094().new Solution();

        digits = new int[]{2, 1, 3, 0};
        answer = new int[]{102, 120, 130, 132, 210, 230, 302, 310, 312, 320};
        x = solution.findEvenNumbers(digits);
        assert Arrays.equals(answer, x) : "Answer is different";

        digits = new int[]{2, 2, 8, 8, 2};
        answer = new int[]{222, 228, 282, 288, 822, 828, 882};
        x = solution.findEvenNumbers(digits);
        assert Arrays.equals(answer, x) : "Answer is different";

        digits = new int[]{3, 7, 5};
        answer = new int[]{};
        x = solution.findEvenNumbers(digits);
        assert Arrays.equals(answer, x) : "Answer is different";

    }
}
