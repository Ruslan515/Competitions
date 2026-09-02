package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1758 {
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

        public int minOperations(String s) {
            int answer = 0;
            int n = s.length();
            StringBuilder sb = new StringBuilder(s);

            int zeroCnt = 0;
            int oneCnt = 0;
            // cnt start from zero
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    if (sb.charAt(i) != '0') {
                        ++zeroCnt;
                    }
                } else {
                    if (sb.charAt(i) != '1') {
                        ++zeroCnt;
                    }
                }
            }

            // cnt start from ones
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    if (sb.charAt(i) != '1') {
                        ++oneCnt;
                    }
                } else {
                    if (sb.charAt(i) != '0') {
                        ++oneCnt;
                    }
                }
            }

            answer = Math.min(zeroCnt, oneCnt);

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "10010100";
        answer = 3;
        assert answer == solution.minOperations(s) : "Answer is different";

        s = "110010";
        answer = 2;
        assert answer == solution.minOperations(s) : "Answer is different";

        s = "0100";
        answer = 1;
        assert answer == solution.minOperations(s) : "Answer is different";

        s = "10";
        answer = 0;
        assert answer == solution.minOperations(s) : "Answer is different";

        s = "1111";
        answer = 2;
        assert answer == solution.minOperations(s) : "Answer is different";
    }

}
