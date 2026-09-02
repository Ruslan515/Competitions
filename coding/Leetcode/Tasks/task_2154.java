//https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19
package leetcode.tasks;

import java.util.HashSet;
import java.util.Set;


public class task_2154 {
class Solution {
public int findFinalValue(int[] nums, int original) {
int answer = original;
Set<Integer> set = new HashSet<>();
for (int num : nums) {
set.add(num);
}
while (true) {
if (set.contains(original)) {
    original *= 2;
} else {
    break;
}
}


return original;
}

}

public void main(String[] args) {
int[] nums;
int original;
int answer;

Solution solution = new Solution();

nums = new int[]{5, 3, 6, 1, 12};
original = 3;
answer = 24;
assert answer == solution.findFinalValue(nums, original) : "Answer is different";

nums = new int[]{5, 3, 6, 1, 12};
original = 3;
answer = 24;
assert answer == solution.findFinalValue(nums, original) : "Answer is different";
}

}
