package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;

public class task_1432 {
    class Solution {
        public ArrayList<Integer> toArray(int num) {
            ArrayList<Integer> list = new ArrayList<>();
            while (num != 0) {
                list.add(num % 10);
                num /= 10;
            }
            return list;
        }

        public int fromArray(ArrayList<Integer> list) {
            int answer = 0;
            int d = 1;
            for (int i = 0; i < list.size(); i++) {
                answer += list.get(i) * d;
                d *= 10;
            }
            return answer;
        }

        public int maxDiff(int num) {
            int answer = 0;
            ArrayList<Integer> listMax = toArray(num);
            ArrayList<Integer> listMin = new ArrayList<>(listMax);
            int a, b, x, y, n;
            n = listMin.size();
            if (n == 1) {
                return 8;
            }
            if (listMax.get(n - 1) != 1) {
                int i = n - 1;
                while (i >= 0 && listMax.get(i) == 9) {
                    --i;
                }
                if (i < 0) {
                    a = num;
                } else {
                    x = listMax.get(i);
                    while (i >= 0) {
                        if (listMax.get(i) == x) {
                            listMax.set(i, 9);
                        }
                        --i;
                    }
                    a = fromArray(listMax);

                }

                i = n - 1;
                y = listMin.get(i);
                while (i >= 0) {
                    if (listMin.get(i) == y) {
                        listMin.set(i, 1);
                    }
                    --i;
                }

                b = fromArray(listMin);
                answer = a - b;
            } else {
                int i = n - 1;
                x = listMax.get(i);
                while (i >= 0) {
                    if (listMax.get(i) == x) {
                        listMax.set(i, 9);
                    }
                    --i;
                }

                a = fromArray(listMax);

                i = n - 1;
                while (i >= 0 && (listMin.get(i) == 1 || listMin.get(i) == 0)) {
                    --i;
                }
                if (i < 0) {
                    b = num;
                } else {
                    y = listMin.get(i);
                    while (i >= 0) {
                        if (listMin.get(i) == y) {
                            listMin.set(i, 0);
                        }
                        --i;
                    }
                    b = fromArray(listMin);
                }
                answer = a - b;

            }

            return answer;
        }

    }

    public static void main(String[] args) {
        int num;

        int answer;

        task_1432.Solution solution = new task_1432().new Solution();

        num = 1101057;
        answer = 8808050;
        assert answer == solution.maxDiff(num) : "Answer is different";

        num = 999;
        answer = 888;
        assert answer == solution.maxDiff(num) : "Answer is different";

        num = 111;
        answer = 888;
        assert answer == solution.maxDiff(num) : "Answer is different";

        num = 123;
        answer = 820;
        assert answer == solution.maxDiff(num) : "Answer is different";

        num = 555;
        answer = 888;
        assert answer == solution.maxDiff(num) : "Answer is different";

        num = 9;
        answer = 8;
        assert answer == solution.maxDiff(num) : "Answer is different";

    }

}
