package leetcode.tasks;


public class task_812 {
    class Solution {
        double getTriangleArea(int x1, int x2, int x3, int y1, int y2, int y3) {
            double area = (double) Math.abs(
                    (x2 - x1) * (y3 - y1) -
                            (x3 - x1) * (y2 - y1)
            ) / 2;
            return area;
        }

        public double largestTriangleArea(int[][] points) {
            double answer = 0;
            int x1, y1, x2, y2, x3, y3;
            int n = points.length;
            double area;
            for (int i = 0; i < n - 2; i++) {
                x1 = points[i][0];
                y1 = points[i][1];
                for (int j = i + 1; j < n; j++) {
                    x2 = points[j][0];
                    y2 = points[j][1];
                    for (int k = j + 1; k < n; k++) {
                        x3 = points[k][0];
                        y3 = points[k][1];
                        area = getTriangleArea(x1, x2, x3, y1, y2, y3);
                        answer = Math.max(answer, area);
                    }
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[][] points;
        double answer;

        Solution solution = new Solution();

        points = new int[][]{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
        answer = 2.00000;
        assert Math.abs(answer - solution.largestTriangleArea(points)) <= 1e5 : "Answer is different";

        points = new int[][]{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
        answer = 2.00000;
        assert Math.abs(answer - solution.largestTriangleArea(points)) <= 1e5 : "Answer is different";
    }

}
