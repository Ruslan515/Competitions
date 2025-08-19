package leetcode.tasks;

public class task_408 {
    class Solution {
        public boolean validWordAbbreviation(String word, String abbr) {
            boolean answer = true;
            int lenWord = word.length();
            int lenAbbr = abbr.length();
            int idxWord = 0;
            int idxAbbr = 0;

            while (idxWord < lenWord && idxAbbr < lenAbbr) {
                while (idxWord < lenWord && idxAbbr < lenAbbr && word.charAt(idxWord) == abbr.charAt(idxAbbr)) {
                    idxWord++;
                    idxAbbr++;
                }
                if (idxWord >= lenWord || idxAbbr >= lenAbbr) {
                    break;
                }
                char tmp = abbr.charAt(idxAbbr);
                if (!(tmp > '0' && tmp <= '9') ) {
                    answer = false;
                    break;
                }
                StringBuilder stringBuilder = new StringBuilder();
                while (idxAbbr < lenAbbr && (abbr.charAt(idxAbbr) >= '0' && abbr.charAt(idxAbbr) <= '9')) {
                    tmp = abbr.charAt(idxAbbr);
                    stringBuilder.append(tmp);
                    idxAbbr++;
                }
                int cnt = Integer.parseInt(stringBuilder.toString());
                idxWord += cnt;
            }

            if (idxWord != lenWord || idxAbbr != lenAbbr) {
                answer = false;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String word, abbr;
        boolean answer;

        Solution solution = new Solution();

        word = "apple";
        abbr = "a2e";
        answer = false;
        assert answer == solution.validWordAbbreviation(word, abbr) : "Answer is different";

        word = "internationalization";
        abbr = "i12iz4n";
        answer = true;
        assert answer == solution.validWordAbbreviation(word, abbr) : "Answer is different";

    }

}
