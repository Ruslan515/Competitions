package leetcode.tasks;

public class task_2264 {
    class Solution {
        public String largestGoodInteger(String num) {
            String answer = "";
            int tmpMax = -1;
            for (int i = 0; i < num.length() - 2; i++) {
                if (num.charAt(i) == num.charAt(i + 1) && num.charAt(i) == num.charAt(i + 2)) {
                    int tmp = Integer.parseInt(num.substring(i, i + 3));
                    tmpMax = Math.max(tmpMax, tmp);
                }
            }
            if (tmpMax == 0) {
                answer = "000";
            } else if (tmpMax > 0) {
                answer = String.valueOf(tmpMax);
            }
            return answer;
        }
    }

    public void main(String[] args) {
        String num;
        String answer;

        Solution solution = new Solution();

        num = "222";
        answer = "222";
        assert answer.equals(solution.largestGoodInteger(num)) : "Answer is different";

        num = "6777133339";
        answer = "777";
        assert answer.equals(solution.largestGoodInteger(num)) : "Answer is different";

        num = "2300019";
        answer = "000";
        assert answer.equals(solution.largestGoodInteger(num)) : "Answer is different";

        num = "42352338";
        answer = "";
        assert answer.equals(solution.largestGoodInteger(num)) : "Answer is different";
    }

}
