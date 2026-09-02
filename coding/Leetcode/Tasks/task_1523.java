//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07
package leetcode.tasks;

public class task_1523 {
    class Solution {
        public int countOdds(int low, int high) {
            int answer = 0;
            if ((low & 1) == 0) {
                ++low;
            }
            if ((high & 1) == 0) {
                --high;
            }
            answer = (high - low) / 2 + 1;

            return answer;
        }
    }

    public void main(String[] args) {
        int low;
        int high;
        int answer;

        Solution solution = new Solution();

        low = 3;
        high = 7;
        answer = 3;
        assert answer == solution.countOdds(low, high) : "Answer is different";

        low = 8;
        high = 10;
        answer = 1;
        assert answer == solution.countOdds(low, high) : "Answer is different";
    }

}

