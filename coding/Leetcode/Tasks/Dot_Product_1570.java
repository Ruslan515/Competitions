package Other;
import java.util.Scanner;

public class Dot_Product_1570 {
    class SparseVector {
        private int[] self_nums;
        SparseVector(int[] nums) {
            self_nums = nums;
        }
        // Return the dotProduct of two sparse vectors
        public int dotProduct(SparseVector vec) {
            int ans = 0;
            int temp;
            for(int i = 0; i < self_nums.length; i++) {
                temp = self_nums[i] * vec.self_nums[i];
                ans += temp;
            }
            return ans;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums1 = new int[n];
        int[] nums2 = new int[n];
        for (int j = 0; j < n; j++)
            nums1[j] = sc.nextInt();
        for (int j = 0; j < n; j++)
            nums2[j] = sc.nextInt();


        // Your SparseVector object will be instantiated and called as such:
//        SparseVector v1 = new SparseVector(nums1);
//        SparseVector v2 = new SparseVector(nums2);
//        int ans = v1.dotProduct(v2);

//        System.out.println(ans);
    }
}

