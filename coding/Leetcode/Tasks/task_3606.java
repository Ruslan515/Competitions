//https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13
package leetcode.tasks;

import java.util.*;

public class task_3606 {
    class Solution {
        public boolean isValid(String code) {
            if (code.isEmpty()) {
                return false;
            }
            boolean answer = true;

            for (char ch : code.toCharArray()) {
                if (!(Character.isLetterOrDigit(ch) || ch == '_')) {
                    answer = false;
                    break;
                }
            }

            return answer;
        }

        public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
            List<String> answer = new ArrayList<>();
            Map<String, ArrayList<String>> mp = new HashMap<>();
            Set<String> categories = new HashSet<>(Arrays.asList("electronics", "grocery", "pharmacy", "restaurant"));
            int n = code.length;
            String currCode, currBusinessLine;
            boolean currActive;
            boolean isValid;
            for (int i = 0; i < n; ++i) {
                currBusinessLine = businessLine[i];
                currActive = isActive[i];
                if (!categories.contains(currBusinessLine) || !currActive) {
                    continue;
                }
                currCode = code[i];
                isValid = isValid(currCode);
                if (isValid) {
                    if (!mp.containsKey(currBusinessLine)) {
                        mp.put(currBusinessLine, new ArrayList<>(List.of(currCode)));
                    } else {
                        mp.get(currBusinessLine).add(currCode);
                    }
                }

            }

            ArrayList<String> arr;
            for (String category : Arrays.asList("electronics", "grocery", "pharmacy", "restaurant")) {
                if (!mp.containsKey(category)) {
                    continue;
                }
                arr = mp.get(category);
                if (arr.isEmpty()) {
                    continue;
                }
                Collections.sort(arr);
                answer.addAll(arr);

            }

            return answer;
        }

    }

    public void main(String[] args) {
        String[] code, businessLine;
        boolean[] isActive;
        List<String> answer;

        Solution solution = new Solution();

        code = new String[]{"bbb", "AAA", "10"};
        businessLine = new String[]{"electronics", "electronics", "electronics"};
        isActive = new boolean[]{true, true, true};
        answer = new ArrayList<>(Arrays.asList("10", "AAA", "bbb"));
        assert answer.equals(solution.validateCoupons(code, businessLine, isActive)) : "Answer is different";

        code = new String[]{"SAVE20", "", "PHARMA5", "SAVE@20"};
        businessLine = new String[]{"restaurant", "grocery", "pharmacy", "restaurant"};
        isActive = new boolean[]{true, true, true, true};
        answer = new ArrayList<>(Arrays.asList("PHARMA5", "SAVE20"));
        assert answer.equals(solution.validateCoupons(code, businessLine, isActive)) : "Answer is different";

        code = new String[]{"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
        businessLine = new String[]{"grocery", "electronics", "invalid"};
        isActive = new boolean[]{false, true, true};
        answer = new ArrayList<>(List.of("ELECTRONICS_50"));
        assert answer.equals(solution.validateCoupons(code, businessLine, isActive)) : "Answer is different";

    }

}
