//https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=problem-list-v2&envId=rolling-hash
package leetcode.tasks;

import java.math.BigInteger;
import java.util.*;

public class task_3042 {
    class Solution {

        public BigInteger exactHash(String s) {
            BigInteger hash = BigInteger.ZERO;
            BigInteger base = BigInteger.valueOf(31);

            for (int i = 0; i < s.length(); i++) {
                hash = hash.multiply(base)
                        .add(BigInteger.valueOf(s.charAt(i)));
            }
            return hash;
        }


        public int countPrefixSuffixPairs(String[] words) {
            int answer = 0;
            int n = words.length;
            BigInteger hashWord, hashPrefix, hashSuffix;
            String currentWord, prefix, suffix, word;
            int sizeWord, sizeCurrentWord;
            for (int i = 0; i < n; i++) {
                word = words[i];
//                hashWord = word.hashCode();
                hashWord = exactHash(word);
                sizeWord = word.length();
                for (int j = i + 1; j < n; j++) {
                    currentWord = words[j];
                    sizeCurrentWord = currentWord.length();
                    if (sizeWord > sizeCurrentWord) {
                        continue;
                    }
                    prefix = currentWord.substring(0, sizeWord);
                    suffix = currentWord.substring(sizeCurrentWord - sizeWord);
//                    hashPrefix = prefix.hashCode();
//                    hashSuffix = suffix.hashCode();
                    hashPrefix = exactHash(prefix);
                    hashSuffix = exactHash(suffix);

                    if (hashWord.equals(hashPrefix) && hashWord.equals(hashSuffix)) {
                        answer++;
                    }
                }

            }

            return answer;
        }

    }

    public void main(String[] args) {
        String[] words;
        int answer;

        Solution solution = new Solution();

        words = new String[]{
                "abbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababba",
                "baababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaababbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaabbaababbaabbabaababbabaabbaababbabaababbaabbabaababbabaabbaababbaabbabaabbaababbabaababbaabbabaab"
        };
        answer = 0;
        assert answer == solution.countPrefixSuffixPairs(words) : "Answer is different";

        words = new String[]{"a", "aba", "ababa", "aa"};
        answer = 4;
        assert answer == solution.countPrefixSuffixPairs(words) : "Answer is different";

        words = new String[]{"pa", "papa", "ma", "mama"};
        answer = 2;
        assert answer == solution.countPrefixSuffixPairs(words) : "Answer is different";

        words = new String[]{"abab", "ab"};
        answer = 0;
        assert answer == solution.countPrefixSuffixPairs(words) : "Answer is different";
    }


}
