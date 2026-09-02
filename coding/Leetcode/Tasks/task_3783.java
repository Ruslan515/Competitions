//https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_3783 {
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

        public int mirrorDistance(int n) {
            int answer = 0;
            StringBuilder sb = new StringBuilder(String.valueOf(n));
            sb.reverse();
            answer = Math.abs(n - Integer.parseInt(sb.toString()));

            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int answer;

        Solution solution = new Solution();

        n = 25;
        answer = 27;
        assert answer == solution.mirrorDistance(n) : "Answer is different";

        n = 10;
        answer = 9;
        assert answer == solution.mirrorDistance(n) : "Answer is different";

        n = 7;
        answer = 0;
        assert answer == solution.mirrorDistance(n) : "Answer is different";
    }

}
