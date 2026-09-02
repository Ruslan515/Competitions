package leetcode.tasks;

public class task_2125 {

    class Solution {
        public int numberOfBeams(String[] bank) {
            int answer = 0;
            int r_high = 0, r_low = 0;
            int m = bank.length;
            int n = bank[0].length();


            int cntOnesHigh = 0;
            while (r_high < m) {

                for (int i = 0; i < n; ++i) {
                    if (bank[r_high].charAt(i) == '1') {
                        cntOnesHigh++;
                    }
                }
                if (cntOnesHigh != 0) {
                    break;
                }
                ++r_high;
            }

            if (r_high == m) {
                return answer;
            }

            while (r_low < m) {
                int cntOnesLow = 0;
                r_low = r_high + 1;
                while (r_low < m) {
                    for (int i = 0; i < n; ++i) {
                        if (bank[r_low].charAt(i) == '1') {
                            cntOnesLow++;
                        }
                    }
                    if (cntOnesLow != 0) {
                        break;
                    }
                    ++r_low;
                }

                if (r_low == m) {
                    break;
                }
                answer += cntOnesHigh * cntOnesLow;
                cntOnesHigh = cntOnesLow;
                r_high = r_low;

            }

            return answer;
        }

    }

    public void main(String[] args) {
        String[] bank;

        int answer;

        Solution solution = new Solution();

        bank = new String[]{"011001", "000000", "010100", "001000"};
        answer = 8;
        assert answer == solution.numberOfBeams(bank) : "Answer is different";

        bank = new String[]{"000", "111", "000"};
        answer = 0;
        assert answer == solution.numberOfBeams(bank) : "Answer is different";

    }

}
