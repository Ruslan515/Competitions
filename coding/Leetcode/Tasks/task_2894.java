// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27
package leetcode.tasks;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class task_2894 {
    class Solution {

        public int differenceOfSums(int n, int m) {
            int answer = 0;
            int sum = n * (n + 1) / 2;
            int cnt = n / m;
            int num2 = m * cnt * (cnt + 1) / 2;
            int num1 = sum - num2;
            answer = num1 - num2;

            return answer;
        }
    }

    public void main(String[] args) {
        Solution solution = new Solution();
        int n, m;
        int answer;
        int x;

        n = 10;
        m = 3;
        answer = 19;
        x = solution.differenceOfSums(n, m);
        assert answer == x;

        n = 5;
        m = 6;
        answer = 15;
        x = solution.differenceOfSums(n, m);
        assert answer == x;

        n = 5;
        m = 1;
        answer = -15;
        x = solution.differenceOfSums(n, m);
        assert answer == x;

    }
}
