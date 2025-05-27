import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;

//https://leetcode.com/problems/count-largest-group/?envType=daily-question&envId=2025-04-23
public class task_1399 {
    class Solution {
        int getSums(int number) {
            int sum = 0;
            while (number > 0) {
                int d = number % 10;
                sum += d;
                number = number / 10;
            }

            return sum;
        }

        public int countLargestGroup(int n) {
            int answer = 0;
            int maxSize = 0;
            HashMap<Integer, List<Integer>> map = new HashMap<>();
            for (int number = 1; number <= n; number++) {
                int sum = getSums(number);
                if (map.containsKey(sum)) {
                    map.get(sum).add(number);
                } else {
                    List<Integer> list = new ArrayList<>();
                    list.add(number);
                    map.put(sum, list);
                }
                maxSize = Math.max(maxSize, map.get(sum).size());
            }
            for (Integer key : map.keySet()) {
                int len = map.get(key).size();
                if (len == maxSize) {
                    ++answer;
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        System.out.println("hello");
        Solution solution = new Solution();
        int n;
        int answer;
        int x;

        n = 13;
        answer = 4;
        x = solution.countLargestGroup(n);
        assert answer == x;

        n = 2;
        answer = 2;
        x = solution.countLargestGroup(n);
        assert answer == x;

    }
}
