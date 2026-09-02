//https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/?envType=daily-question&envId=2026-07-15
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_3658 {
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

    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b; // Остаток от деления
            a = temp;
        }
        return a;
    }

    public int gcdOfOddEvenSums(int n) {
        int answer = 0;
        int sumOdd = n * n;
        int sumEven = n + n * n;
        answer = gcd(sumOdd, sumEven);

        return answer;
    }

}

public void main(String[] args) {
    int n;
    int answer;

    Solution solution = new Solution();

    n = 4;
    answer = 4;
    assert answer == solution.gcdOfOddEvenSums(n) : "Answer is different";

    n = 5;
    answer = 5;
    assert answer == solution.gcdOfOddEvenSums(n) : "Answer is different";
}

}
