package leetcode.tasks;


import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class task_1733 {
    class Solution {
        public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
            int cntFriends = friendships.length;
            int answer = cntFriends;
            int cntLang = languages.length;
            Set<Integer>[] setLanguages = new HashSet[cntLang];
            for (int i = 0; i < cntLang; i++) {
                setLanguages[i] = new HashSet<>();
                for (int j = 0; j < languages[i].length; j++) {
                    setLanguages[i].add(languages[i][j]);
                }
            }
            int u, v;
            for (int i = 1; i <= n; ++i) {
                int cnt = 0;
                int[] newLanguages = new int[cntFriends];
                for (int j = 0; j < cntFriends; ++j) {
                    u = friendships[j][0] - 1;
                    v = friendships[j][1] - 1;
                    Set<Integer> uLang = setLanguages[u];
                    Set<Integer> vLang = setLanguages[v];
                    boolean check = !Collections.disjoint(uLang, vLang);
                    if (check) {
                        continue;
                    }
                    if (!uLang.contains(i) && newLanguages[u] == 0) {
                        ++cnt;
                        newLanguages[u] = 1;
                    }
                    if (!vLang.contains(i) && newLanguages[v] == 0) {
                        ++cnt;
                        newLanguages[v] = 1;
                    }
                }
                answer = Math.min(answer, cnt);
//                System.out.println(answer);
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int[][] languages, friendships;
        int answer;

        Solution solution = new Solution();

        n = 11;
        languages = new int[][]{{3, 11, 5, 10, 1, 4, 9, 7, 2, 8, 6}, {5, 10, 6, 4, 8, 7}, {6, 11, 7, 9}, {11, 10, 4}, {6, 2, 8, 4, 3}, {9, 2, 8, 4, 6, 1, 5, 7, 3, 10}, {7, 5, 11, 1, 3, 4}, {3, 4, 11, 10, 6, 2, 1, 7, 5, 8, 9}, {8, 6, 10, 2, 3, 1, 11, 5}, {5, 11, 6, 4, 2}};
        friendships = new int[][]{{7, 9}, {3, 7}, {3, 4}, {2, 9}, {1, 8}, {5, 9}, {8, 9}, {6, 9}, {3, 5}, {4, 5}, {4, 9}, {3, 6}, {1, 7}, {1, 3}, {2, 8}, {2, 6}, {5, 7}, {4, 6}, {5, 8}, {5, 6}, {2, 7}, {4, 8}, {3, 8}, {6, 8}, {2, 5}, {1, 4}, {1, 9}, {1, 6}, {6, 7}};
        answer = 0;
        assert answer == solution.minimumTeachings(n, languages, friendships) : "Answer is different";

        n = 2;
        languages = new int[][]{{1, 2}, {2}, {1, 2}};
        friendships = new int[][]{{1, 2}, {1, 3}, {2, 3}};
        answer = 0;
        assert answer == solution.minimumTeachings(n, languages, friendships) : "Answer is different";

        n = 3;
        languages = new int[][]{{2}, {1, 3}, {1, 2}, {3}};
        friendships = new int[][]{{1, 4}, {1, 2}, {3, 4}, {2, 3}};
        answer = 2;
        assert answer == solution.minimumTeachings(n, languages, friendships) : "Answer is different";

        n = 2;
        languages = new int[][]{{1}, {2}, {1, 2}};
        friendships = new int[][]{{1, 2}, {1, 3}, {2, 3}};
        answer = 1;
        assert answer == solution.minimumTeachings(n, languages, friendships) : "Answer is different";

    }

}
