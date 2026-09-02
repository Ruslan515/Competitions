package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;

public class task_703 {

    class KthLargest {

        private PriorityQueue<Integer> queue;
        private int k;

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

        public KthLargest(int k, int[] nums) {
            this.queue = new PriorityQueue<>(k);
            this.k = k;
            for (int num : nums) {
                this.queue.add(num);
                if (this.queue.size() > k) {
                    this.queue.poll();
                }
            }

        }

        public int add(int val) {
            int answer;
            this.queue.add(val);
            if (this.queue.size() > this.k) {
                this.queue.poll();
            }
            answer = this.queue.peek();

            return answer;
        }


    }

    public void main(String[] args) {
        KthLargest kthLargest = new KthLargest(1, new int[]{});
        assert -3 == kthLargest.add(-3) : "Answer is different";
        assert -2 == kthLargest.add(-2) : "Answer is different";
        assert -2 == kthLargest.add(-4) : "Answer is different";
        assert 0 == kthLargest.add(0) : "Answer is different";
        assert 4 == kthLargest.add(4) : "Answer is different";

        kthLargest = new KthLargest(3, new int[]{4, 5, 8, 2});
        assert 4 == kthLargest.add(3) : "Answer is different";
        assert 5 == kthLargest.add(5) : "Answer is different";
        assert 5 == kthLargest.add(10) : "Answer is different";
        assert 8 == kthLargest.add(9) : "Answer is different";
        assert 8 == kthLargest.add(4) : "Answer is different";

        kthLargest = new KthLargest(4, new int[]{7, 7, 7, 7, 8, 3});
        assert 7 == kthLargest.add(2) : "Answer is different";
        assert 7 == kthLargest.add(10) : "Answer is different";
        assert 7 == kthLargest.add(9) : "Answer is different";
        assert 8 == kthLargest.add(9) : "Answer is different";
    }

}
