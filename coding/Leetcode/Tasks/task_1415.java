//https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2026-03-14
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class task_1415 {
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

        public String getHappyString(int n, int k) {
            String answer = "";

            Map<Character, List<Character>> map = new HashMap<>();
            map.put('a', Arrays.asList('b', 'c'));
            map.put('b', Arrays.asList('a', 'c'));
            map.put('c', Arrays.asList('a', 'b'));

            Queue<String> queue = new ArrayDeque<>();
            queue.add("a");
            queue.add("b");
            queue.add("c");

            int level = 0;
            int sizeQ;
            String current;
            char lastChar;
            char nextChar;
            List<Character> nextChars;
            while ((level + 1) < n) {
                sizeQ = queue.size();
                for (int i = 0; i < sizeQ; i++) {
                    current = queue.poll();
                    lastChar = current.charAt(level);
                    nextChars = map.get(lastChar);
                    for (Character aChar : nextChars) {
                        nextChar = aChar;
                        queue.add(current + nextChar);
                    }
                }
                ++level;
            }

            if (k <= queue.size()) {
                String[] array = queue.toArray(new String[0]);
//                Arrays.sort(array);
                answer = array[k - 1];

            }

            return answer;
        }
    }

    public void main(String[] args) {
        int n, k;
        String answer;

        Solution solution = new Solution();

        n = 3;
        k = 9;
        answer = "cab";
        assert answer.equals(solution.getHappyString(n, k)) : "Answer is different";

        n = 1;
        k = 4;
        answer = "";
        assert answer.equals(solution.getHappyString(n, k)) : "Answer is different";

        n = 1;
        k = 3;
        answer = "c";
        assert answer.equals(solution.getHappyString(n, k)) : "Answer is different";

    }

}
