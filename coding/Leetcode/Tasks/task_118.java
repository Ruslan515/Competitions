package leetcode.tasks;

import java.util.ArrayList;
import java.util.List;

public class task_118 {
    class Solution {
        public List<List<Integer>> generate(int numRows) {
            List<List<Integer>> answer = new ArrayList<>();
            answer.add(new ArrayList<>(List.of(1)));
            for (int row = 2; row <= numRows; row++) {

            }

            return answer;
        }
    }

    public void main(String[] args) {
        int numRows;
        List<List<Integer>> answer;

        Solution solution = new Solution();
        int[][] x;

        numRows = 5;
        x = new int[][]{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        answer = this.convert2List(x);
        assert answer == solution.generate(numRows) : "Answer is different";

        numRows = 1;
        x = new int[][]{{1}};
        answer = convert2List(x);
        assert answer == solution.generate(numRows) : "Answer is different";

    }

    public List<List<Integer>> convert2List(int[][] matrix) {
        List<List<Integer>> list = new ArrayList<>();
        for (int[] row : matrix) {
            List<Integer> subList = new ArrayList<>();
            for (int num : row) {
                subList.add(num);
            }
            list.add(subList);
        }
        return list;
    }

}
