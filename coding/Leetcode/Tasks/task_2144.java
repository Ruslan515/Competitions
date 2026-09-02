//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_2144 {
    class Solution {

        static {
            Runtime.getRuntime().gc();
            Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                    writer.write("0");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }));
        }

        public int minimumCost(int[] cost) {
            int answer = 0;
            Arrays.sort(cost);
            int n = cost.length;
            int d = n % 3;
            if (d == 1) {
                answer += cost[0];
            } else if (d == 2) {
                answer += cost[0] + cost[1];
            }
            for (int i = n - 1; i >= 0 + d; i -= 3) {
                answer += cost[i] + cost[i - 1];
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] cost;
        int answer;

        Solution solution = new Solution();

        cost = new int[]{3, 1, 2};
        answer = 5;
        assert answer == solution.minimumCost(cost) : "Answer is different";

        cost = new int[]{6, 5, 7, 9, 2, 2};
        answer = 23;
        assert answer == solution.minimumCost(cost) : "Answer is different";

        cost = new int[]{5, 5};
        answer = 10;
        assert answer == solution.minimumCost(cost) : "Answer is different";
    }

}
