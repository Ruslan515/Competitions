package leetcode.tasks;


import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class task_904 {
    class Solution {
        public int totalFruit(int[] fruits) {
            int answer = -1;
            int n = fruits.length;
            int left1 = 0, left2 = 0, right1 = 0, right2 = 0;
            while (left1 < n && left2 < n) {
                Set<Integer> set = new HashSet<>();
                Map<Integer, Integer> map = new HashMap<>();
                int idx = 0;
                while (set.size() <=2) {
                    int val = fruits[idx], key= idx;
                    map.put(key, val);
                    set.add(fruits[idx]);
                    ++idx;
                }
                int prev = fruits[idx - 1];
                


            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] fruits;
        int answer;

        Solution solution = new Solution();

        fruits = new int[]{1, 2, 1};
        answer = 3;
        assert answer == solution.totalFruit(fruits) : "Answer is different";

        fruits = new int[]{0, 1, 2, 2};
        answer = 3;
        assert answer == solution.totalFruit(fruits) : "Answer is different";

        fruits = new int[]{1, 2, 3, 2, 2};
        answer = 4;
        assert answer == solution.totalFruit(fruits) : "Answer is different";

    }

}
