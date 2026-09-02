package leetcode.tasks;

public class task_3461 {
    class Solution {
        public boolean hasSameDigits(String s) {
            StringBuilder sb = new StringBuilder(s);

            while (sb.length() != 2) {
                int n = sb.length();
                StringBuilder tmp = new StringBuilder(n - 1);

                for (int i = 1; i < n; ++i) {
                    int x1 = sb.charAt(i - 1) - '0';
                    int x2 = sb.charAt(i) - '0';
                    tmp.append((x1 + x2) % 10);
                }
                sb = tmp;
            }

            return sb.charAt(0) == sb.charAt(1);
        }
    }

    public void main(String[] args) {
        String s;
        boolean answer;

        Solution solution = new Solution();

        s = "3902";
        answer = true;
        assert answer == solution.hasSameDigits(s) : "Answer is different";

        s = "34789";
        answer = false;
        assert answer == solution.hasSameDigits(s) : "Answer is different";


    }

}
