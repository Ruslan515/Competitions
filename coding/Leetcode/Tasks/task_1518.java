package leetcode.tasks;


public class task_1518 {
    class Solution {
        public int numWaterBottles(int numBottles, int numExchange) {
            int answer = 0;
            int cntEmpty = 0;
            int tmp;
            while (true) {
                answer += numBottles;
                tmp = numBottles + cntEmpty;
                numBottles = tmp / numExchange;
                cntEmpty = tmp % numExchange;
                if (numBottles == 0) {
                    break;
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int numBottles, numExchange;
        int answer;

        Solution solution = new Solution();

        numBottles = 9;
        numExchange = 3;
        answer = 13;
        assert answer == solution.numWaterBottles(numBottles, numExchange) : "Answer is different";

        numBottles = 15;
        numExchange = 4;
        answer = 19;
        assert answer == solution.numWaterBottles(numBottles, numExchange) : "Answer is different";
    }

}
