//https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20
package leetcode.tasks;

import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

public class task_2011 {
    class Solution {
        public int finalValueAfterOperations(String[] operations) {
            int answer = 0;
            Set<String> increment = new HashSet<>(Arrays.asList("++X", "X++"));
            Set<String> decrement = new HashSet<>(Arrays.asList("--X", "X--"));
            for (String operation : operations) {
                if (increment.contains(operation)) {
                    answer++;
                } else if (decrement.contains(operation)) {
                    answer--;
                }
            }
            return answer;
        }

    }

    public void main(String[] args) {
        String[] operations;
        int answer;

        Solution solution = new Solution();

        operations = new String[]{"--X", "X++", "X++"};
        answer = 1;
        assert answer == solution.finalValueAfterOperations(operations) : "Answer is different";

        operations = new String[]{"++X", "++X", "X++"};
        answer = 3;
        assert answer == solution.finalValueAfterOperations(operations) : "Answer is different";

        operations = new String[]{"X++", "++X", "--X", "X--"};
        answer = 0;
        assert answer == solution.finalValueAfterOperations(operations) : "Answer is different";
    }

}
