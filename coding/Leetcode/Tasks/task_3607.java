//https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06
package leetcode.tasks;

import java.util.*;


public class task_3607 {
    class Solution {
        public int[] processQueries(int c, int[][] connections, int[][] queries) {
            ArrayList<Integer> answer = new ArrayList<>();

            Set<Set<Integer>> components = new HashSet<>();
            int u, v;

            for (int[] connection : connections) {
                u = connection[0];
                v = connection[1];
                Set<Integer> compU = null, compV = null;
                for (Set<Integer> component : components) {
                    if (component.contains(u)) {
                        compU = component;
                    }
                    if (component.contains(v)) {
                        compV = component;
                    }
                }

                if (compU != null && compV != null) {
                    if (compU != compV) {
                        compU.addAll(compV);
                        Iterator<Set<Integer>> iterator = components.iterator();
                        while (iterator.hasNext()) {
                            if (iterator.next() == compV) {
                                iterator.remove();
                                break;
                            }
                        }

                    }
                } else if (compU != null) {
                    compU.add(v);
                } else if (compV != null) {
                    compV.add(u);
                } else {
                    Set<Integer> component = new HashSet<>();
                    component.add(u);
                    component.add(v);
                    components.add(component);
                }
            }

            boolean label = true;
            for (int i = 1; i <= c; ++i) {
                label = true;
                for (Set<Integer> component : components) {
                    if (component.contains(i)) {
                        label = false;
                        break;
                    }
                }
                if (label) {
                    Set<Integer> component = new HashSet<>();
                    component.add(i);
                    components.add(component);
                }
            }

            Set<PriorityQueue<Integer>> setHeap = new HashSet<>();
            Map<Integer, PriorityQueue> mapHeap = new HashMap<>();
            for (Set<Integer> component : components) {
                PriorityQueue<Integer> heap = new PriorityQueue<>();
                heap.addAll(component);
                setHeap.add(heap);
                for (int i : component) {
                    mapHeap.put(i, heap);
                }
            }

            Map<Integer, Boolean> online = new HashMap<>();
            for (int i = 1; i <= c; ++i) {
                online.put(i, true);
            }

            int num;
            int top;
            for (int[] query : queries) {
                num = query[1];
                if (query[0] == 1) {
                    if (online.get(num)) {
                        answer.add(num);
                    } else {
                        int tmp = -1;
                        PriorityQueue<Integer> currentHeap = mapHeap.get(num);
                        while (!currentHeap.isEmpty()) {
                            top = currentHeap.peek();
                            if (online.get(top)) {
                                tmp = top;
                                break;
                            }
                            mapHeap.get(num).poll();
                        }
                        answer.add(tmp);
                    }
                } else {
                    online.put(num, false);
                }
            }

            return answer.stream().mapToInt(Integer::intValue).toArray();
        }
    }

    public void main(String[] args) {
        int c;
        int[][] connections;
        int[][] queries;
        int[] answer;

        Solution solution = new Solution();

        c = 10;
        connections = new int[][]{{10, 8}, {8, 1}, {10, 7}, {6, 4}, {4, 2}, {3, 2}, {1, 3}};
        queries = new int[][]{{2, 8}, {2, 3}, {2, 10}, {1, 9}, {1, 4}, {1, 2}, {1, 7}, {1, 8}, {1, 6}, {1, 5}, {2, 3}, {2, 6}, {2, 3}, {1, 4}, {2, 5}, {1, 3}, {1, 5}, {1, 4}, {1, 10}, {1, 4}, {1, 1}, {2, 1}, {2, 2}, {2, 6}, {2, 9}, {1, 7}, {1, 4}, {1, 4}, {1, 10}, {1, 8}, {2, 4}, {1, 7}, {2, 10}, {1, 4}, {1, 5}, {2, 7}, {1, 4}, {1, 3}};
        answer = new int[]{9, 4, 2, 7, 1, 6, 5, 4, 2, -1, 4, 1, 4, 1, 7, 4, 4, 4, 4, 7, -1, -1, -1, -1};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";

        c = 4;
        connections = new int[][]{{3, 1}, {2, 4}, {2, 1}, {1, 4}};
        queries = new int[][]{{2, 3}, {2, 1}, {1, 1}, {1, 3}, {2, 2}, {2, 1}, {1, 2}, {2, 3}, {1, 4}, {2, 2}, {1, 1}, {2, 2}, {2, 1}, {2, 2}};
        answer = new int[]{2, 2, 4, 4, 4};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";


        c = 7;
        connections = new int[][]{{1, 2}, {4, 3}, {7, 3}, {1, 7}, {7, 6}, {2, 6}};
        queries = new int[][]{{1, 1}, {2, 5}, {1, 1}, {2, 1}, {2, 4}, {1, 4}, {2, 2}};
        answer = new int[]{1, 1, 2};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";

        c = 4;
        connections = new int[][]{{1, 2}, {3, 4}, {4, 1}, {4, 2}, {3, 2}, {1, 3}};
        queries = new int[][]{{2, 3}, {2, 1}, {1, 4}, {2, 4}, {1, 3}, {2, 4}, {2, 4}, {1, 4}, {2, 2}, {1, 1}, {1, 2}, {1, 2}, {1, 3}, {2, 1}, {1, 2}, {2, 4}, {1, 2}, {2, 2}, {2, 2}, {2, 1}, {2, 1}, {1, 1}, {2, 3}, {1, 2}, {2, 2}, {2, 1}, {2, 2}, {1, 2}, {2, 2}, {2, 2}, {1, 1}, {1, 2}, {2, 1}};
        answer = new int[]{4, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";

        c = 3;
        connections = new int[][]{};
        queries = new int[][]{{1, 1}, {2, 1}, {1, 1}};
        answer = new int[]{1, -1};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";

        c = 5;
        connections = new int[][]{{1, 2}, {1, 3}, {4, 5}};
        queries = new int[][]{{1, 3}, {2, 3}, {1, 3}, {2, 4}, {1, 4}};
        answer = new int[]{3, 1, 5};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";


        c = 5;
        connections = new int[][]{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
        queries = new int[][]{{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
        answer = new int[]{3, 2, 3};
        assert Arrays.equals(answer, solution.processQueries(c, connections, queries)) : "Answer is different";


    }

}
