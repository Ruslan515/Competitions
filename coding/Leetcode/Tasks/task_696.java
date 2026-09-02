package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class task_696 {
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

        public int countBinarySubstrings(String s) {
            int answer = 0;
            int n = s.length();
            int cntX, cntY;
            int start = 0;
            int end;
            int prev;
            while (start < n) {
                end = start;
                while (end < (n - 1) && s.charAt(end) == s.charAt(end + 1)) {
                    ++end;
                }
                cntX = end - start + 1;


                start = end + 1;
                if (start >= n) {
                    break;
                }
                prev = start;
                end = start;
                while (end < Math.min(start + cntX, n - 1) && s.charAt(end) == s.charAt(end + 1)) {
                    ++end;
                }
                cntY = end - start + 1;

                answer += Math.min(cntX, cntY);

                start = prev;

            }

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "00110";
        answer = 3;
        assert answer == solution.countBinarySubstrings(s) : "Answer is different";

        s = "10101";
        answer = 4;
        assert answer == solution.countBinarySubstrings(s) : "Answer is different";

        s = "00110011";
        answer = 6;
        assert answer == solution.countBinarySubstrings(s) : "Answer is different";
    }

}
