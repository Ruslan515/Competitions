package leetcode.weekly.w_471;

import java.util.HashMap;
import java.util.Map;

public class task_q3 {
    class Solution {
        public int longestBalanced(String s) {
            int n = s.length();
            int answer = 1;

            int maxSingle = 1;
            int current = 1;
            for (int i = 1; i < n; i++) {
                if (s.charAt(i) == s.charAt(i - 1)) {
                    current++;
                    if (current > maxSingle) {
                        maxSingle = current;
                    }
                } else {
                    current = 1;
                }
            }
            answer = Math.max(answer, maxSingle);

            Map<String, Integer> dict_all = new HashMap<>();
            Map<String, Integer> dict_ab = new HashMap<>();
            Map<String, Integer> dict_ac = new HashMap<>();
            Map<String, Integer> dict_bc = new HashMap<>();

            dict_all.put("0,0", -1);
            dict_ab.put("0,0", -1);
            dict_ac.put("0,0", -1);
            dict_bc.put("0,0", -1);

            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                char ch = s.charAt(j);
                if (ch == 'a') a++;
                else if (ch == 'b') b++;
                else if (ch == 'c') c++;

                int diff_ab = a - b;
                int diff_ac = a - c;
                int diff_bc = b - c;

                String state_all = diff_ab + "," + diff_ac;
                String state_ab = diff_ab + "," + c;
                String state_ac = diff_ac + "," + b;
                String state_bc = diff_bc + "," + a;

                if (dict_all.containsKey(state_all)) {
                    int i_index = dict_all.get(state_all);
                    answer = Math.max(answer, j - i_index);
                } else {
                    dict_all.put(state_all, j);
                }

                if (dict_ab.containsKey(state_ab)) {
                    int i_index = dict_ab.get(state_ab);
                    answer = Math.max(answer, j - i_index);
                } else {
                    dict_ab.put(state_ab, j);
                }

                if (dict_ac.containsKey(state_ac)) {
                    int i_index = dict_ac.get(state_ac);
                    answer = Math.max(answer, j - i_index);
                } else {
                    dict_ac.put(state_ac, j);
                }

                if (dict_bc.containsKey(state_bc)) {
                    int i_index = dict_bc.get(state_bc);
                    answer = Math.max(answer, j - i_index);
                } else {
                    dict_bc.put(state_bc, j);
                }
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        task_q3 outer = new task_q3();
        Solution solution = outer.new Solution();

        String s;
        int answer;

        s = "a";
        answer = 1;
        assert answer == solution.longestBalanced(s) : "Test case 1 failed";

        s = "aabcc";
        answer = 3;
        assert answer == solution.longestBalanced(s) : "Test case 2 failed";

        s = "abbac";
        answer = 4;
        assert answer == solution.longestBalanced(s) : "Test case 3 failed";

        s = "aba";
        answer = 2;
        assert answer == solution.longestBalanced(s) : "Test case 4 failed";

        System.out.println("All test cases passed!");
    }
}