package leetcode.tasks;

public class task_2928 {
    class Solution {
        public int distributeCandies(int n, int limit) {
            int answer = 0;
            for (int i = 0; i <= limit; i++) {
                for (int j = 0; j <= limit; j++) {
                    for (int k = 0; k <= limit; k++) {
                        int sums = i + j + k;
                        if (sums == n) {
                            ++answer;
                        }

                    }
                }
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        int n, limit;
        int answer;

        Solution solution = new task_2928().new Solution();

        n = 5;
        limit = 2;
        answer = 3;
        assert answer == solution.distributeCandies(n, limit) : "Answer is different";

        n = 3;
        limit = 3;
        answer = 10;
        assert answer == solution.distributeCandies(n, limit) : "Answer is different";

    }
}
