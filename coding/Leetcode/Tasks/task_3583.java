//https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09
package leetcode.tasks;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class task_3583 {
    class Solution {
        public int specialTriplets(int[] nums) {
            long answer = 0;
            Map<Integer, List<Integer>> map = new HashMap<>();
            int key;
            for (int i = 0; i < nums.length; i++) {
                key = nums[i];
                if (!map.containsKey(key)) {
                    map.put(key, new ArrayList<>());
                }
                map.get(key).add(i);
            }
            int x, mid;
            for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
                mid = entry.getKey();
                x = 2 * mid;
                if (map.containsKey(x) && map.get(x).size() > 1) {
                    if (mid == 0) {
                        int size = map.get(x).size();
                        if (size == 3) {
                            ++answer;
                        } else {
                            int first = size - 2;
                            for (int i = 0; i < first; i++) {
                                answer += (long) (i + 1) * (size - i - 1);
                            }
                        }
                        continue;
                    }
                    List<Integer> listMid = map.get(mid);
                    List<Integer> listX = map.get(x);
                    for (int idxMid : listMid) {
                        int valLeft = listX.get(0);
                        int valRight = listX.get(listX.size() - 1);
                        if (!(valLeft <= idxMid && valRight >= idxMid)) {
                            continue;
                        }
                        int left = 0;
                        int right = listX.size() - 1;

                        int middle = 0;
                        int val;
                        while (left <= right) {
                            middle = left + (right - left) / 2;
                            val = listX.get(middle);
                            if (val > idxMid) {
                                right = middle - 1;
                            } else {
                                left = middle + 1;
                            }
                        }
                        long cntLeft = middle + 1;
                        long cntRight = listX.size() - middle;
                        answer += (long) cntLeft * cntRight;

                    }
                }
            }


            return (int) answer % 1000000007;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{8, 4, 2, 8, 8, 4};
        answer = 3;
        assert answer == solution.specialTriplets(nums) : "Answer is different";

        nums = new int[]{8, 4, 2, 8, 4};
        answer = 2;
        assert answer == solution.specialTriplets(nums) : "Answer is different";

        nums = new int[]{0, 1, 0, 0};
        answer = 1;
        assert answer == solution.specialTriplets(nums) : "Answer is different";

        nums = new int[]{6, 3, 6};
        answer = 1;
        assert answer == solution.specialTriplets(nums) : "Answer is different";

        nums = new int[]{8, 4, 2, 8, 8, 4, 8};
        answer = 6;
        assert answer == solution.specialTriplets(nums) : "Answer is different";

    }

}
