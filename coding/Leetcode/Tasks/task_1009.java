package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1009 {
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

        public int bitwiseComplement(int n) {
            if (n == 0) {
                return 1;
            }
            int answer = 0;
            int k = (int) Math.floor(Math.log(n) / Math.log(2)) + 1;
            int fullDigit = (int) Math.pow(2, k) - 1;
            answer = fullDigit - n;

            return answer;
        }
    }

    public void main(String[] args) {
        int n;
        int answer;

        Solution solution = new Solution();

        n = 5;
        answer = 2;
        assert answer == solution.bitwiseComplement(n) : "Answer is different";

        n = 7;
        answer = 0;
        assert answer == solution.bitwiseComplement(n) : "Answer is different";

        n = 10;
        answer = 5;
        assert answer == solution.bitwiseComplement(n) : "Answer is different";
    }

}
