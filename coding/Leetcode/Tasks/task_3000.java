package leetcode.tasks;

public class task_3000 {
    class Solution {
        public int areaOfMaxDiagonal(int[][] dimensions) {
            int answer = 0;
            double maxRect = 0, currRect;
            int maxArea = 0, currArea = 0;
            int n = dimensions.length;
            int a, b;
            for (int i = 0; i < n; i++) {
                a = dimensions[i][0];
                b = dimensions[i][1];
                currRect = Math.sqrt(a * a + b * b);
                if (currRect > maxRect) {
                    maxRect = currRect;
                    maxArea = a * b;
                } else if (currRect == maxRect) {
                    currArea = a * b;
                    if (currArea > maxArea) {
                        maxArea = currArea;
                    }
                }
            }
            answer = maxArea;


            return answer;
        }

    }

    public void main(String[] args) {
        int[][] dimensions;
        int answer;

        Solution solution = new Solution();

        dimensions = new int[][]{{9, 3}, {8, 6}};
        answer = 48;
        assert answer == solution.areaOfMaxDiagonal(dimensions) : "Answer is different";

        dimensions = new int[][]{{3, 4}, {4, 3}};
        answer = 12;
        assert answer == solution.areaOfMaxDiagonal(dimensions) : "Answer is different";
    }

}
