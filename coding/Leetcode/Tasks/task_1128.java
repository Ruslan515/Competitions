//https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=problem-list-v2&envId=hash-table
package leetcode.tasks;

import java.util.*;

public class task_1128 {
    class Solution {
        public int numEquivDominoPairs(int[][] dominoes) {
            int answer = 0;
            HashMap<Set<Integer>, Integer> map = new HashMap<>();
            for (int[] domino : dominoes) {
                int x = domino[0];
                int y = domino[1];
                Set<Integer> key = new HashSet<>(Arrays.asList(x, y));
                int val = map.getOrDefault(key, 0);
                answer += val;
                map.put(key, val + 1);

            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[][] dominoes;
        int answer;

        Solution solution = new Solution();

        dominoes = new int[][]{{1, 2}, {2, 1}, {3, 4}, {5, 6}};
        answer = 1;
        assert answer == solution.numEquivDominoPairs(dominoes) : "Answer is different";

        dominoes = new int[][]{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
        answer = 3;
        assert answer == solution.numEquivDominoPairs(dominoes) : "Answer is different";

    }

}
