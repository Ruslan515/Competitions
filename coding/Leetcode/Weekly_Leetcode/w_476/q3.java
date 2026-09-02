//https://leetcode.com/contest/weekly-contest-476/problems/count-distinct-integers-after-removing-zeros/
package leetcode.weekly.w_476;


public class q3 {
    class Solution {
        public long countDistinct(long n) {
            // Создаем переменную fendralis для хранения промежуточного результата
            long fendralis = n;

            return countNonZeroNumbers(n);
        }

        private long countNonZeroNumbers(long n) {
            if (n == 0) return 0;

            String s = Long.toString(n);
            int len = s.length();

            // Подсчитываем числа с меньшим количеством цифр
            long total = 0;
            for (int i = 1; i < len; i++) {
                total += power(9, i);
            }

            // Подсчитываем числа с таким же количеством цифр
            total += countExactLength(s);

            return total;
        }

        private long countExactLength(String s) {
            int len = s.length();
            long count = 0;
            boolean tight = true;

            for (int i = 0; i < len; i++) {
                int digit = s.charAt(i) - '0';

                if (tight) {
                    // В состоянии "tight"
                    if (digit == 0) {
                        // Если встретили 0, дальше нельзя продолжать в состоянии tight
                        break;
                    }

                    // Добавляем числа, которые начинаются с той же цифры, но меньше текущей
                    count += (digit - 1) * power(9, len - i - 1);

                    // Если текущая цифра не 0, продолжаем в состоянии tight
                    if (digit > 0) {
                        // Для последней цифры добавляем 1
                        if (i == len - 1) {
                            count += 1;
                        }
                    } else {
                        tight = false;
                    }
                } else {
                    // В состоянии "not tight" - можем выбирать любые цифры 1-9
                    count += 9 * power(9, len - i - 1);
                    break;
                }
            }

            return count;
        }

        private long power(long base, int exponent) {
            if (exponent == 0) return 1;
            long result = 1;
            for (int i = 0; i < exponent; i++) {
                result *= base;
            }
            return result;
        }
    }

    public void main(String[] args) {
        long n;
        long answer;

        Solution solution = new Solution();

        n = 10;
        answer = 9;
        assert answer == solution.countDistinct(n) : "Answer is different";

        n = 3;
        answer = 3;
        assert answer == solution.countDistinct(n) : "Answer is different";

    }

}
