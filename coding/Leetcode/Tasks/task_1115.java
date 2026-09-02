//https://leetcode.com/problems/print-foobar-alternately/description/?envType=problem-list-v2&envId=concurrency
package leetcode.tasks;

public class task_1115 {
    class FooBar {
        private int n;
        private int step = 0;
        private final Object lock = new Object();

        public FooBar(int n) {
            this.n = n;
        }

        public void foo(Runnable printFoo) throws InterruptedException {
            synchronized (lock) {
                for (int i = 0; i < n; i++) {
                    while (step % 2 != 0) {
                        lock.wait();
                    }
                    // printFoo.run() outputs "foo". Do not change or remove this line.
                    printFoo.run();
                    ++step;
                    lock.notifyAll();
                }
            }
        }

        public void bar(Runnable printBar) throws InterruptedException {
            synchronized (lock) {
                for (int i = 0; i < n; i++) {
                    while (step % 2 == 0) {
                        lock.wait();
                    }
                    // printBar.run() outputs "bar". Do not change or remove this line.
                    printBar.run();
                    ++step;
                    lock.notifyAll();
                }
            }
        }
    }

    public void main(String[] args) {
        FooBar fooBar = new FooBar(3);
        Thread t1 = new Thread(() -> {
            try {
                fooBar.foo(() -> System.out.println("foo"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        Thread t2 = new Thread(() -> {
            try {
                fooBar.bar(() -> System.out.println("bar"));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        t2.start();
        t1.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
