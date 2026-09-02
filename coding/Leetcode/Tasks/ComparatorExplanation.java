package leetcode.tasks;

import java.util.PriorityQueue;

public class ComparatorExplanation {
    public static void visual1() {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> {
                    System.out.println("a: " + a[0] + " ," + a[1]);
                    System.out.println("b: " + b[0] + " ," + b[1]);
                    int result = b[0] - a[0];
                    System.out.println("Сравниваем [" + a[0] + "," + a[1] + "] с [" +
                            b[0] + "," + b[1] + "] -> результат: " + result);
                    return result;
                }
        );

        pq.offer(new int[]{5, 100});
        pq.offer(new int[]{10, 200});
        pq.offer(new int[]{7, 200});
        pq.offer(new int[]{3, 50});

        System.out.println("\nИзвлечение элементов:");
        while (!pq.isEmpty()) {
            int[] element = pq.poll();
            System.out.println("Извлечен: [" + element[0] + ", " + element[1] + "]");
        }

    }

    public static void visual2() {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> {
                    int result = b[0] - a[0];
                    System.out.println("Сравниваем [" + a[0] + "," + a[1] + "] с [" +
                            b[0] + "," + b[1] + "] -> результат: " + result);
                    return result;
                }
        );

        pq.offer(new int[]{3, 50});
        pq.offer(new int[]{5, 100});
        pq.offer(new int[]{10, 200});


        System.out.println("\nИзвлечение элементов:");
        while (!pq.isEmpty()) {
            int[] element = pq.poll();
            System.out.println("Извлечен: [" + element[0] + ", " + element[1] + "]");
        }

    }

    public static void main(String[] args) {
        visual1();
        System.out.println("############################################\n############################################");
        visual2();
    }
}