//https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
package leetcode.tasks;

import java.util.Arrays;

public class task_2138 {
    class Solution {
        public String[] divideString(String s, int k, char fill) {
            int n = s.length();
            int x = n % k != 0 ? 1 : 0;
            int cnt = n / k + x;
            String[] answer = new String[cnt];

            int i = 0;
            for (int start = 0; start < (n / k) * k; start += k) {
                int end = start + k;
                String substr = s.substring(start, end);
                answer[i] = substr;
                ++i;
            }
            int start = (n / k) * k;
            if (start < n) {
                String substr = s.substring(start, n);
                int d = n % k;
                d = k - d;
                String ss = String.valueOf(fill).repeat(d);
                substr += ss;
                answer[cnt - 1] = substr;
            }


            return answer;
        }

    }

    public void main(String[] args) {
        String s;
        int k;
        char fill;
        String[] answer;

        Solution solution = new Solution();

        s = "ctoyjrwtngqwt";
        k = 8;
        fill = 'n';
        answer = new String[]{"ctoyjrwt", "ngqwtnnn"};
        assert Arrays.equals(answer, solution.divideString(s, k, fill)) : "Answer is different";

        s = "abcdefghij";
        k = 3;
        fill = 'x';
        answer = new String[]{"abc", "def", "ghi", "jxx"};
        assert Arrays.equals(answer, solution.divideString(s, k, fill)) : "Answer is different";

        s = "abcdefghi";
        k = 3;
        fill = 'x';
        answer = new String[]{"abc", "def", "ghi"};
        assert Arrays.equals(answer, solution.divideString(s, k, fill)) : "Answer is different";

    }

}
