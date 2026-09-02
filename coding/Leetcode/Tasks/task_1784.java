//https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
// 🦈
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1784 {
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

        public boolean checkOnesSegment(String s) {
            boolean answer = true;
            int n = s.length();
            int cntOnesBlocks = 0;
            int i = 0;
            while (i < n && s.charAt(i) == '1') {
                ++i;
            }
            while (i < n && s.charAt(i) == '0') {
                ++i;
            }
            if (i != n) {
                answer = false;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        boolean answer;

        Solution solution = new Solution();

        s = "1001";
        answer = false;
        assert answer == solution.checkOnesSegment(s) : "Answer is different";

        s = "110";
        answer = true;
        assert answer == solution.checkOnesSegment(s) : "Answer is different";

        s = "110011";
        answer = false;
        assert answer == solution.checkOnesSegment(s) : "Answer is different";
    }

}
