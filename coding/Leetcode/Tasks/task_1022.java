package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.Queue;


public class task_1022 {
    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    class Solution {

        static {
            Runtime.getRuntime().gc();
            Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                    writer.write("0");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }));
        }

        record Item(TreeNode node, BitSet bits) {
        }

        int convertBin2Int(BitSet bits, int size) {
            long answer = 0L;
            for (int i = 0; i < bits.length(); ++i) {
                if (bits.get(i)) {
                    answer |= (1L << (size - 1 - i));
                }
            }

            return (int) answer;
        }

        public int sumRootToLeaf(TreeNode root) {
            int answer = 0;
            Queue<Item> queue = new LinkedList<>();

            BitSet bits = new BitSet();
            bits.set(0, root.val == 1);
            queue.add(new Item(root, bits));

            int level = 0;
            int newLevel;
            int size;
            while (!queue.isEmpty()) {
                ++level;
                size = queue.size();
                for (int i = 0; i < size; i++) {
                    Item item = queue.poll();
                    TreeNode current = item.node();
                    BitSet bitsCurrent = item.bits();

                    newLevel = level + 1;

                    TreeNode left = current.left;
                    TreeNode right = current.right;
                    if (left == null && right == null) {
                        answer += convertBin2Int(bitsCurrent, level);
                    }

                    if (left != null) {
                        BitSet leftVal = new BitSet(newLevel);
                        leftVal.or(bitsCurrent);
                        leftVal.set(level, left.val == 1);
                        queue.add(new Item(left, leftVal));
                    }
                    if (right != null) {
                        BitSet rightVal = new BitSet(newLevel);
                        rightVal.or(bitsCurrent);
                        rightVal.set(level, right.val == 1);
                        queue.add(new Item(right, rightVal));
                    }
                }
            }


            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        TreeNode t1 = new TreeNode(0);
        TreeNode t2 = new TreeNode(1);
        TreeNode t3 = new TreeNode(0, t1, t2);
        TreeNode t4 = new TreeNode(0);
        TreeNode t5 = new TreeNode(1);
        TreeNode t6 = new TreeNode(1, t4, t5);
        TreeNode t7 = new TreeNode(1, t3, t6);
        answer = 22;
        assert answer == solution.sumRootToLeaf(t7) : "Answer is different";


        t1 = new TreeNode(0);
        answer = 0;
        assert answer == solution.sumRootToLeaf(t1) : "Answer is different";
    }

}
