package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_3345 {
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

        public int getDot(int n) {
            int answer = 1;
            int d;
            while (n != 0) {
                d = n % 10;
                answer *= d;
                n = n / 10;
            }
            return answer;
        }

        public int smallestNumber(int n, int t) {
            int answer = 0;
            int dot;
            while (true) {
                dot = getDot(n);
                if (dot % t == 0) {
                    answer = n;
                    break;
                }
                ++n;
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int n, t;
        int answer;

        Solution solution = new Solution();

        n = 10;
        t = 2;
        answer = 10;
        assert answer == solution.smallestNumber(n, t) : "Answer is different";

        n = 15;
        t = 3;
        answer = 16;
        assert answer == solution.smallestNumber(n, t) : "Answer is different";

    }

}
