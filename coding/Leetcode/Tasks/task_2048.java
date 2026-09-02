//https://leetcode.com/problems/next-greater-numerically-balanced-number/?envType=daily-question&envId=2025-10-24
package leetcode.tasks;

import java.util.*;

public class task_2048 {
    class Solution {
        public static int[] generateUniqueNumberPermutations(int[] digits) {
            List<Integer> resultList = generateUniquePermutationsList(digits);

            // Конвертируем List<Integer> в int[]
            int[] result = new int[resultList.size()];
            for (int i = 0; i < resultList.size(); i++) {
                result[i] = resultList.get(i);
            }
            return result;
        }

        // Внутренний метод, работающий со списком
        private static List<Integer> generateUniquePermutationsList(int[] digits) {
            List<Integer> result = new ArrayList<>();
            if (digits == null || digits.length == 0) {
                return result;
            }

            int[] sortedDigits = digits.clone();
            Arrays.sort(sortedDigits);

            boolean[] used = new boolean[digits.length];
            generateNumberPermutations(sortedDigits, used, new ArrayList<>(), result);

            return result;
        }

        private static void generateNumberPermutations(int[] digits, boolean[] used,
                                                       List<Integer> current, List<Integer> result) {
            if (current.size() == digits.length) {
                // Преобразуем список цифр в число
                int number = 0;
                for (int digit : current) {
                    number = number * 10 + digit;
                }
                result.add(number);
                return;
            }

            for (int i = 0; i < digits.length; i++) {
                if (used[i]) {
                    continue;
                }

                if (i > 0 && digits[i] == digits[i - 1] && !used[i - 1]) {
                    continue;
                }

                used[i] = true;
                current.add(digits[i]);

                generateNumberPermutations(digits, used, current, result);

                // Backtracking
                current.remove(current.size() - 1);
                used[i] = false;
            }
        }

        public int nextBeautifulNumber(int n) {
            int answer = 1;
            if (n == 0) {
                return answer;
            }

            int[] tmp1 = new int[]{1};
            int[] tmp2 = generateUniqueNumberPermutations(new int[]{2, 2});
            int[] tmp3 = generateUniqueNumberPermutations(new int[]{1, 2, 2});
            int[] tmp31 = new int[]{333};
            int[] tmp4 = generateUniqueNumberPermutations(new int[]{1, 3, 3, 3});
            int[] tmp41 = new int[]{4444};
            int[] tmp5 = generateUniqueNumberPermutations(new int[]{2, 2, 3, 3, 3});
            int[] tmp51 = new int[]{55555};
            int[] tmp52 = generateUniqueNumberPermutations(new int[]{1, 4, 4, 4, 4});
            int[] tmp6 = generateUniqueNumberPermutations(new int[]{1, 2, 2, 3, 3, 3});
            int[] tmp61 = new int[]{666666};
            int[] tmp62 = generateUniqueNumberPermutations(new int[]{2, 2, 4, 4, 4, 4});
            int[] tmp63 = generateUniqueNumberPermutations(new int[]{1, 5, 5, 5, 5, 5});
            int[] tmp7 = generateUniqueNumberPermutations(new int[]{1, 2, 2, 4, 4, 4, 4});
            int[] tmp71 = generateUniqueNumberPermutations(new int[]{1, 2, 2, 5, 5, 5, 5, 5});
            int[] tmp72 = generateUniqueNumberPermutations(new int[]{3, 3, 3, 4, 4, 4, 4});
            int[] tmp73 = generateUniqueNumberPermutations(new int[]{1, 6, 6, 6, 6, 6, 6});
            int[] result = new int[
                    tmp1.length +
                            tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length +
                            tmp51.length +
                            tmp52.length +
                            tmp62.length +
                            tmp63.length +
                            tmp7.length + tmp71.length + tmp72.length + tmp73.length
                    ];
            System.arraycopy(tmp1, 0, result, 0, tmp1.length);
            System.arraycopy(tmp2, 0, result, tmp1.length, tmp2.length);
            System.arraycopy(tmp3, 0, result, tmp1.length + tmp2.length, tmp3.length);
            System.arraycopy(tmp4, 0, result, tmp1.length + tmp2.length + tmp3.length, tmp4.length);
            System.arraycopy(tmp5, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length, tmp5.length);
            System.arraycopy(tmp6, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length, tmp6.length);
            System.arraycopy(tmp61, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length, tmp61.length);
            System.arraycopy(tmp31, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length, tmp31.length);
            System.arraycopy(tmp41, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length, tmp41.length);
            System.arraycopy(tmp51, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length, tmp51.length);
            System.arraycopy(tmp52, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length, tmp52.length);
            System.arraycopy(tmp62, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length, tmp62.length);
            System.arraycopy(tmp63, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length + tmp62.length, tmp63.length);
            System.arraycopy(tmp7, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length + tmp62.length + tmp63.length, tmp7.length);
            System.arraycopy(tmp71, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length + tmp62.length + tmp63.length + tmp7.length, tmp71.length);
            System.arraycopy(tmp72, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length + tmp62.length + tmp63.length + tmp7.length + tmp71.length, tmp72.length);
            System.arraycopy(tmp73, 0, result, tmp1.length + tmp2.length + tmp3.length + tmp4.length + tmp5.length + tmp6.length + tmp61.length + tmp31.length + tmp41.length + tmp51.length + tmp52.length + tmp62.length + tmp63.length + tmp7.length + tmp71.length + tmp72.length, tmp73.length);


            Arrays.sort(result);
            int current;
            for (int i = 0; i < result.length; i++) {
                current = result[i];
                if (current > n) {
                    answer = current;
                    break;
                }

            }

            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int answer;

        Solution solution = new Solution();

        n = 748601;
        answer = 1224444;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";

        n = 135909;
        answer = 155555;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";

        n = 238;
        answer = 333;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";

        n = 1;
        answer = 22;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";

        n = 1000;
        answer = 1333;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";

        n = 3000;
        answer = 3133;
        assert answer == solution.nextBeautifulNumber(n) : "Answer is different";
    }

}
