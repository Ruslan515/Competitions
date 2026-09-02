//https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08
package leetcode.tasks;

import java.util.HashSet;
import java.util.Set;

public class task_1925 {
    class Solution {
        public int countTriples(int n) {
            int answer = 0;
            int cSquare;
            double c;
            long cInt;
            for (int a = 1; a <= n; a++) {
                for (int b = 1; b <= n; b++) {
                    cSquare = a * a + b * b;
                    c = Math.sqrt(cSquare);
                    if (c > n) {
                        continue;
                    }
                    cInt = Math.round(c);
                    if ((c - cInt) == 0) {
                        ++answer;
                    }
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int answer;

        Solution solution = new Solution();

        n = 12;
        answer = 4;
        assert answer == solution.countTriples(n) : "Answer is different";

        n = 5;
        answer = 2;
        assert answer == solution.countTriples(n) : "Answer is different";

        n = 10;
        answer = 4;
        assert answer == solution.countTriples(n) : "Answer is different";
    }

}
