//https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
package leetcode.tasks;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class task_1394 {
    class Solution {
        public int findLucky(int[] arr) {
            int answer = -1;
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < arr.length; i++) {
                map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
            }

            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                if (entry.getValue() == entry.getKey()) {
                    answer = Math.max(entry.getKey(), answer);
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] arr;
        int answer;

        Solution solution = new Solution();

        arr = new int[]{2, 2, 3, 4};
        answer = 2;
        assert answer == solution.findLucky(arr) : "Answer is different";


        arr = new int[]{1, 2, 2, 3, 3, 3};
        answer = 3;
        assert answer == solution.findLucky(arr) : "Answer is different";


        arr = new int[]{2, 2, 2, 3, 3};
        answer = -1;
        assert answer == solution.findLucky(arr) : "Answer is different";
    }

}
