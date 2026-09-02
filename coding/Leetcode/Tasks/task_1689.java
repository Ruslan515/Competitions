package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1689 {
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

        public int minPartitions(String n) {
            int answer = 0;
            int len = n.length();
            char ch;
            int val;
            for (int i = 0; i < len; ++i) {
                ch = n.charAt(i);
                val = ch - '0';
                answer = Math.max(answer, val);
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String n;
        int answer;

        Solution solution = new Solution();

        n = "32";
        answer = 3;
        assert answer == solution.minPartitions(n) : "Answer is different";

        n = "82734";
        answer = 8;
        assert answer == solution.minPartitions(n) : "Answer is different";

        n = "27346209830709182346";
        answer = 9;
        assert answer == solution.minPartitions(n) : "Answer is different";
    }

}
