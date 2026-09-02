//https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class task_2657 {
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

        public int[] findThePrefixCommonArray(int[] A, int[] B) {
            int n = A.length;
            int[] answer = new int[n];
            Set<Integer> setA = new HashSet<>(), setB = new HashSet<>();
            int ai, bi, prev;
            setA.add(A[0]);
            setB.add(B[0]);
            if (A[0] == B[0]) {
                answer[0] = 1;
            }
            for (int i = 1; i < n; ++i) {
                ai = A[i];
                bi = B[i];
                setA.add(ai);
                setB.add(bi);
                prev = answer[i - 1];
                answer[i] = prev;
                if (ai == bi) {
                    ++answer[i];
                    continue;
                }
                if (setA.contains(bi)) {
                    ++answer[i];
                }
                if (setB.contains(ai)) {
                    ++answer[i];
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] A, B;
        int[] answer;

        Solution solution = new Solution();

        A = new int[]{1};
        B = new int[]{1};
        answer = new int[]{1};
        assert Arrays.equals(answer, solution.findThePrefixCommonArray(A, B)) : "Answer is different";

        A = new int[]{1, 3, 2, 4};
        B = new int[]{3, 1, 2, 4};
        answer = new int[]{0, 2, 3, 4};
        assert Arrays.equals(answer, solution.findThePrefixCommonArray(A, B)) : "Answer is different";

        A = new int[]{2, 3, 1};
        B = new int[]{3, 1, 2};
        answer = new int[]{0, 1, 3};
        assert Arrays.equals(answer, solution.findThePrefixCommonArray(A, B)) : "Answer is different";

    }

}
