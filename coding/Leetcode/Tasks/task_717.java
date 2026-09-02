//https://leetcode.com/problems/1-bit-and-2-bit-characters/description/?envType=daily-question&envId=2025-11-18
package leetcode.tasks;

public class task_717 {
    class Solution {
        public boolean isOneBitCharacter(int[] bits) {
            boolean answer = true;
            int n = bits.length;
            int i = 0;
            while (i < n - 1) {
                if (bits[i] == 1) {
                    i += 2;
                } else {
                    i++;
                }
            }
            if (i == n) {
                answer = false;
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] bits;
        boolean answer;

        Solution solution = new Solution();

        bits = new int[]{1, 0, 0};
        answer = true;
        assert answer == solution.isOneBitCharacter(bits) : "Answer is different";

        bits = new int[]{1, 1, 1, 0};
        answer = false;
        assert answer == solution.isOneBitCharacter(bits) : "Answer is different";

    }

}
