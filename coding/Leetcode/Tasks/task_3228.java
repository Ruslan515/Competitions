//https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13
package leetcode.tasks;


public class task_3228 {
    class Solution {
        public int maxOperations(String s) {
            int answer = 0;
            int n = s.length();
            int i = 0;
            char current;
            int start, diff;
            int cntOnes = 0;
            while (i < n) {
                // find first 1
                while (i < n) {
                    current = s.charAt(i);
                    if (current == '1') {
                        break;
                    }
                    i++;
                }


                answer += cntOnes;

                // find first 0
                start = i;
                while (i < n) {
                    current = s.charAt(i);
                    if (current == '0') {
                        break;
                    }
                    i++;
                }
                diff = i - start;
                cntOnes += diff;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "1001101";
        answer = 4;
        assert answer == solution.maxOperations(s) : "Answer is different";

        s = "00111";
        answer = 0;
        assert answer == solution.maxOperations(s) : "Answer is different";

    }

}
