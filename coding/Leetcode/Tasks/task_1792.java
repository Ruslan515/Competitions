package leetcode.tasks;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;

public class task_1792 {
    class Item {
        double key;
        int[] val;

        public Item(double key, int[] val) {
            this.key = key;
            this.val = val;
        }
    }

    class Solution {
        public double maxAverageRatio(int[][] classes, int extraStudents) {
            double answer = 0;
            PriorityQueue<Item> maxHeap = new PriorityQueue<>(
                    (a, b) -> Double.compare(b.key, a.key)
            );
            int n = classes.length;
            int pass, total;
            double currRatio, nextRatio, diff;
            for (int i = 0; i < n; i++) {
                pass = classes[i][0];
                total = classes[i][1];
                currRatio = (double) pass / total;
                nextRatio = (double) (pass + 1) / (total + 1);
                diff = nextRatio - currRatio;
                maxHeap.add(new Item(diff, classes[i]));
            }
            Item currItem;
            for (int i = 0; i < extraStudents; i++) {
                currItem = maxHeap.poll();
                pass = currItem.val[0] + 1;
                total = currItem.val[1] + 1;
                currRatio = (double) pass / total;
                nextRatio = (double) (pass + 1) / (total + 1);
                diff = nextRatio - currRatio;
                maxHeap.add(new Item(diff, new int[]{pass, total}));
            }
            while (!maxHeap.isEmpty()) {
                currItem = maxHeap.poll();
                answer += (double) currItem.val[0] / currItem.val[1];
            }
            answer /= n;


            return answer;
        }

    }

    public void main(String[] args) {
        int[][] classes;
        int extraStudents;
        double answer;

        Solution solution = new Solution();

        double EPSILON = 1e-5;

        classes = new int[][]{{1, 2}, {3, 5}, {2, 2}};
        extraStudents = 2;
        answer = 0.78333;
        assert Math.abs(answer - solution.maxAverageRatio(classes, extraStudents)) < EPSILON : "Answer is different";

        classes = new int[][]{{2, 4}, {3, 9}, {4, 5}, {2, 10}};
        extraStudents = 4;
        answer = 0.53485;
        assert Math.abs(answer - solution.maxAverageRatio(classes, extraStudents)) < EPSILON : "Answer is different";

    }

}
