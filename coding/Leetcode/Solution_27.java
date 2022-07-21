//https://leetcode.com/problems/remove-element/
import java.text.MessageFormat;

class Solution_27 {
    public static int removeElement(int[] nums, int val) {
        int k = 0;
        boolean label = false;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val && i != (nums.length - 1)) {
                label = true;
                k++;
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] != val) {
                        k--;
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
            } else if (i == (nums.length - 1) && (nums[i] == val)) {
                k++;
                label = true;
            }

        }
        int ans = 0;
        if (k == 0 && label)
            ans = 0;
        else if (k != 0 && !label) {
            ans = nums.length;
        } else
            ans = nums.length - k;
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {2};
        int k = removeElement(nums, 3);
        System.out.println(k);
        for (int i = 0; i < nums.length; i++)
            System.out.print(MessageFormat.format("{0} ", nums[i]));
    }

}