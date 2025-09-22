package leetcode.tasks;

public class task_680 {
    class Solution {
        public boolean validPalindrome(String s) {
            boolean answer = true;
            int n = s.length();
            int left = 0, right = n - 1;
            char currLeft, currRight, nextLeft, nextRight;
            int cnt = 0;
            while (left < right) {
                currLeft = s.charAt(left);
                currRight = s.charAt(right);
                if (currLeft == currRight) {
                    ++left;
                    --right;
                } else {
                    if (cnt >= 1) {
                        answer = false;
                        break;
                    }
                    nextLeft = s.charAt(left + 1);
                    nextRight = s.charAt(right - 1);
                    if (nextLeft == currRight) {
                        ++left;
                    } else if (nextRight == currLeft) {
                        --right;
                    } else {
                        answer = false;
                        break;
                    }
                    ++cnt;

                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        String s;
        boolean answer;

        Solution solution = new Solution();

        s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "zryxeededexyz";
        answer = false;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "abccbbba";
        answer = false;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "abccbba";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";


        s = "a";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "aa";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "ab";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "aba";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "abca";
        answer = true;
        assert answer == solution.validPalindrome(s) : "Answer is different";

        s = "abc";
        answer = false;
        assert answer == solution.validPalindrome(s) : "Answer is different";

    }

}
