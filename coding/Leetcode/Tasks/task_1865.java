//https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
package leetcode.tasks;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class task_1865 {
    class FindSumPairs {
        Map<Integer, Set<String>> map = new HashMap<>();
        int[] nums1, nums2;

        public FindSumPairs(int[] nums1, int[] nums2) {
            this.nums1 = nums1;
            this.nums2 = nums2;
            int key;
            String val;
            for (int i = 0; i < nums1.length; i++) {
                for (int j = 0; j < nums2.length; j++) {
                    key = nums1[i] + nums2[j];
                    val = i + "_" + j;
                    if (!this.map.containsKey(key)) {
                        this.map.put(key, new HashSet<>());
                    }
                    this.map.get(key).add(val);

                }
            }

        }

        public void add(int index, int val) {
            int curr2 = nums2[index], curr1;
            int key;
            String value;

            for (int i = 0; i < nums1.length; i++) {
                curr1 = nums1[i];
                key = curr1 + curr2;
                value = i + "_" + index;
                if (this.map.containsKey(key)) {
                    this.map.get(key).remove(value);
                }
                key += val;
                if (!this.map.containsKey(key)) {
                    this.map.put(key, new HashSet<>());
                }
                this.map.get(key).add(value);
            }
            this.nums2[index] += val;

        }

        public int count(int tot) {

            int answer = 0;
            if (this.map.containsKey(tot)) {
                answer = this.map.get(tot).size();
            }

            return answer;
        }
    }

    public void main(String[] args) {
        FindSumPairs findSumPairs = new FindSumPairs(
                new int[]{9, 70, 14, 9, 76},
                new int[]{26, 26, 58, 23, 74, 68, 68, 78, 58, 26}
        );

        findSumPairs.add(6, 10);
        findSumPairs.add(5, 6);

        assert 2 == findSumPairs.count(32) : "Answer is different";// return 2; pairs (5,2), (5,4) make 3 + 5

        findSumPairs.add(3, 55);
        findSumPairs.add(9, 32);
        findSumPairs.add(9, 16);
        findSumPairs.add(1, 48);
        findSumPairs.add(1, 4);
        findSumPairs.add(0, 52);
        findSumPairs.add(8, 20);
        findSumPairs.add(9, 4);
        assert 2 == findSumPairs.count(88) : "Answer is different";// return 2; pairs (5,2), (5,4) make 3 + 5
        assert 7 == findSumPairs.count(154) : "Answer is different";// return 2; pairs (5,2), (5,4) make 3 + 5


//        FindSumPairs findSumPairs = new FindSumPairs(new int[]{1, 1, 2, 2, 2, 3}, new int[]{1, 4, 5, 2, 5, 4});
//        assert 8 == findSumPairs.count(7) : "Answer is different";  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
//        findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
//        assert 2 == findSumPairs.count(8) : "Answer is different";// return 2; pairs (5,2), (5,4) make 3 + 5
//        assert 1 == findSumPairs.count(4) : "Answer is different";  // return 1; pair (5,0) makes 3 + 1
//        findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
//        findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
//        assert 11 == findSumPairs.count(7) : "Answer is different";  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
    }

}
