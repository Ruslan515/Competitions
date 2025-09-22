package leetcode.tasks;

import java.util.Arrays;
import java.util.Collections;

public class task_3021 {
    class Solution {
        public long flowerGame(int n, int m) {
            long answer = 0;
            int cntZeroN = 0, cntOneN = 0;
            int cntZeroM = 0, cntOneM = 0;
            cntZeroN = n / 2;
            cntOneN = n / 2 + n % 2;
            cntZeroM = m / 2;
            cntOneM = m / 2 + m % 2;
            long dotZeroOne = (long) cntZeroN * cntOneM;
            long dotOneZero = (long) cntOneN * cntZeroM;
            answer = dotZeroOne + dotOneZero;

            return answer;
        }

    }

    public void main(String[] args) {
        int n, m;
        long answer;

        Solution solution = new Solution();

        n = 3;
        m = 2;
        answer = 3;
        assert answer == solution.flowerGame(n, m) : "Answer is different";

        n = 1;
        m = 1;
        answer = 0;
        assert answer == solution.flowerGame(n, m) : "Answer is different";

    }

}
