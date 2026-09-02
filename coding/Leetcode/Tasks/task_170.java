//https://leetcode.com/problems/two-sum-iii-data-structure-design/description/?envType=weekly-question&envId=2025-11-08
package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;

public class task_170 {
    class TwoSum {
        Map<Integer, Integer> map;

        public TwoSum() {
            this.map = new HashMap<>();
        }

        public void add(int number) {
            this.map.put(number, this.map.getOrDefault(number, 0) + 1);
        }

        public boolean find(int value) {
            boolean answer = false;
            int x1, x2, cnt;
            for (Map.Entry<Integer, Integer> entry : this.map.entrySet()) {
                x1 = entry.getKey();
                x2 = value - x1;
                cnt = entry.getValue();
                if (x1 != x2 && this.map.containsKey(x2) || (x1 == x2 && cnt > 1)) {
                    answer = true;
                    break;
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        boolean answer;

        TwoSum twoSum = new TwoSum();
        twoSum.add(0);

        answer = false;
        assert answer == twoSum.find(0) : "Answer is different";

        twoSum.add(1);   // [] --> [1]
        twoSum.add(3);   // [1] --> [1,3]
        twoSum.add(5);   // [1,3] --> [1,3,5]

        answer = true;
        assert answer == twoSum.find(4) : "Answer is different";  // 1 + 3 = 4, return true

        answer = false;
        assert answer == twoSum.find(7) : "Answer is different";  // No two integers sum up to 7, return false
    }
}
