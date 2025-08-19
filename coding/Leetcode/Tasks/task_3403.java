// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-question&envId=2025-06-04
package leetcode.tasks;

public class task_3403 {
    class Solution {
        public String answerString(String word, int numFriends) {
            String answer = "" + word.charAt(0);
            int n = word.length();
            for (int size = n - numFriends + 1; size >= 1; --size) {
                for (int start = 0; start < n - size; ++start) {
                    boolean flag = false;
                    int sizeAns = answer.length();
                    char currAns, currWord;
                    int idx;
                    for (int i = 0; i < Math.min(size, sizeAns); ++i) {
                        idx = start + i;
                        currAns = answer.charAt(idx);
                        currWord = word.charAt(idx);
                        if (currWord > currAns) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        answer = word.substring(start, size);
                        return answer;
                    }

                }

            }


            return answer;
        }
    }

    public static void main(String[] args) {
        String word;
        int numFriends;
        String answer;

        Solution solution = new task_3403().new Solution();

        word = "dbca";
        numFriends = 2;
        answer = "dbc";
        assert answer == solution.answerString(word, numFriends) : "Answer is different";

        word = "gggg";
        numFriends = 4;
        answer = "g";
        assert answer == solution.answerString(word, numFriends) : "Answer is different";

    }
}
