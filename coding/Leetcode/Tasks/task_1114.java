//https://leetcode.com/problems/print-in-order/submissions/?envType=problem-list-v2&envId=concurrency
package leetcode.tasks;

public class task_1114 {
    class Foo {
        private int step = 1;
        private final Object lock = new Object();

        public void first(Runnable printFirst) throws InterruptedException {
            synchronized (lock) {
                printFirst.run();
                step = 2;
                lock.notifyAll();
            }
        }

        public void second(Runnable printSecond) throws InterruptedException {
            synchronized (lock) {
                while (step != 2) {
                    lock.wait();
                }
                printSecond.run();
                step = 3;
                lock.notifyAll();
            }
        }

        public void third(Runnable printThird) throws InterruptedException {
            synchronized (lock) {
                while (step != 3) {
                    lock.wait();
                }
                printThird.run();
            }
        }
    }

    public void main(String[] args) {
        Foo foo = new Foo();
        Thread t1 = new Thread(() -> {
            try {
                foo.first(() -> System.out.println("first"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        Thread t2 = new Thread(() -> {
            try {
                foo.second(() -> System.out.println("second"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        Thread t3 = new Thread(() -> {
            try {
                foo.third(() -> System.out.println("third"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        t3.start();
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
