package leetcode.tasks;

public class task_125 {
    class Solution {
        public boolean isPalindrome(String s) {
            boolean answer = true;
            int n = s.length();
            int left = 0, right = n - 1;
            char chL, chR;
            while (left < right) {
                while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                    ++left;
                }
                chL = s.charAt(left);
                while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                    --right;
                }
                chR = s.charAt(right);
                if (Character.toLowerCase(chL) != Character.toLowerCase(chR)) {
                    answer = false;
                    break;
                }
                ++left;
                --right;

            }

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        boolean answer;

        Solution solution = new Solution();

        s = "A man, a plan, a canal: Panama";
        answer = true;
        assert answer == solution.isPalindrome(s) : "Answer is different";

        s = "race a car";
        answer = false;
        assert answer == solution.isPalindrome(s) : "Answer is different";

        s = " ";
        answer = true;
        assert answer == solution.isPalindrome(s) : "Answer is different";
    }


}
