package leetcode.bw.bw_167;


public class task_q1 {
    class Solution {
        public boolean scoreBalance(String s) {
            boolean answer = false;
            int sumsScore = 0;
            int score;
            for (char ch : s.toCharArray()) {
                score = ch - 'a' + 1;
                sumsScore += score;
            }
            if (sumsScore % 2 != 0) {
                return answer;
            }
            int halfScore = sumsScore / 2;
            int currSum = 0;
            for (char ch : s.toCharArray()) {
                score = ch - 'a' + 1;
                currSum += score;
                if (currSum == halfScore) {
                    answer = true;
                    break;
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        String s;
        boolean answer;

        Solution solution = new Solution();

        s = "adcb";
        answer = true;
        assert answer == solution.scoreBalance(s) : "Answer is different";

        s = "bace";
        answer = false;
        assert answer == solution.scoreBalance(s) : "Answer is different";

    }

}
