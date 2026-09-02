//https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/?envType=weekly-question&envId=2025-10-22
package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;


public class task_1570 {
    class SparseVector {
        Map<Integer, Integer> currMap = new HashMap<>();

        SparseVector(int[] nums) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    currMap.put(i, nums[i]);
                }
            }

        }

        // Return the dotProduct of two sparse vectors
        public int dotProduct(SparseVector vec) {
            AtomicInteger answer = new AtomicInteger(0);
            int currLen, otherLen;
            currLen = currMap.size();
            otherLen = vec.currMap.size();
            if (currLen > otherLen) {
                vec.currMap.forEach(
                        (key, value) -> {
                            if (currMap.containsKey(key)) {
                                answer.addAndGet(value * currMap.get(key));
                            }
                        }
                );
            }
            else {
                currMap.forEach(
                        (key, value) -> {
                            if (vec.currMap.containsKey(key)) {
                                answer.addAndGet(value * vec.currMap.get(key));
                            }
                        }
                );
            }


            return answer.get();
        }
    }

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);1


    public void main(String[] args) {
        int answer;
        int[] nums1, nums2;

        nums1 = new int[]{1, 0, 0, 2, 3};
        nums2 = new int[]{0, 3, 0, 4, 0};
        answer = 8;
        SparseVector v1 = new SparseVector(nums1);
        SparseVector v2 = new SparseVector(nums2);
        assert answer == v1.dotProduct(v2) : "Answer is not correct";

        nums1 = new int[]{0, 1, 0, 0, 0};
        nums2 = new int[]{0, 0, 0, 0, 2};
        answer = 0;
        v1 = new SparseVector(nums1);
        v2 = new SparseVector(nums2);
        assert answer == v1.dotProduct(v2) : "Answer is not correct";


        nums1 = new int[]{0, 1, 0, 0, 2, 0, 0};
        nums2 = new int[]{1, 0, 0, 0, 3, 0, 4};
        answer = 6;
        v1 = new SparseVector(nums1);
        v2 = new SparseVector(nums2);
        assert answer == v1.dotProduct(v2) : "Answer is not correct";

    }
}
