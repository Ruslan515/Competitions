package leetcode.tasks;


public class task_165 {
    class Solution {
        public int compareVersion(String version1, String version2) {
            int answer = 0;
            String[] splitString1 = version1.split("\\.");
            String[] splitString2 = version2.split("\\.");
            int n1 = splitString1.length;
            int n2 = splitString2.length;
            int minLen = Math.min(n1, n2);
            int x1, x2;
            for (int i = 0; i < minLen; i++) {
                x1 = Integer.parseInt(splitString1[i]);
                x2 = Integer.parseInt(splitString2[i]);
                if (x1 > x2) {
                    answer = 1;
                    break;
                } else if (x1 < x2) {
                    answer = -1;
                    break;
                }
            }
            if (answer == 0) {
                if (n1 > n2) {
                    for (int i = minLen; i < n1; i++) {
                        x1 = Integer.parseInt(splitString1[i]);
                        x2 = 0;
                        if (x1 > x2) {
                            answer = 1;
                            break;
                        }
                    }
                } else if (n1 < n2) {
                    for (int i = minLen; i < n2; i++) {
                        x1 = 0;
                        x2 = Integer.parseInt(splitString2[i]);
                        if (x1 < x2) {
                            answer = -1;
                            break;
                        }
                    }
                }


            }
            return answer;
        }
    }

    public void main(String[] args) {
        String version1, version2;
        int answer;

        Solution solution = new Solution();

        version1 = "7.5.2.4";
        version2 = "7.5.3";
        answer = -1;
        assert answer == solution.compareVersion(version1, version2) : "Answer is different";

        version1 = "1.0";
        version2 = "1.0.0.0";
        answer = 0;
        assert answer == solution.compareVersion(version1, version2) : "Answer is different";

        version1 = "1.2";
        version2 = "1.10";
        answer = -1;
        assert answer == solution.compareVersion(version1, version2) : "Answer is different";

        version1 = "1.01";
        version2 = "1.001";
        answer = 0;
        assert answer == solution.compareVersion(version1, version2) : "Answer is different";

    }

}
