//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;

class Solution_26 {
    public static int removeDuplicates(int[] nums) {
        HashSet<Integer> hash_set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (!hash_set.contains(nums[i])) {
                hash_set.add(nums[i]);
            }
        }
        int i = 0;
        Iterator<Integer> it = hash_set.iterator();
        while (it.hasNext()) {
            nums[i] = it.next();
            i++;
        }

        Arrays.sort(nums, 0, hash_set.size());
        return hash_set.size();

    }

    public static void main(String[] args) {
        int[] nums = new int[] {-3,-1,0,0,0,3,3};
        int k = removeDuplicates(nums);
        System.out.println(k);
        for (int i = 0; i < nums.length; i++)
            System.out.print(MessageFormat.format("{0} ", nums[i]));
    }

}