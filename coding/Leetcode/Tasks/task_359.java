package leetcode.tasks;

import java.util.HashMap;

public class task_359 {
    class Logger {
        HashMap<String, Integer> map = new HashMap<>();

        public Logger() {
        }

        public boolean shouldPrintMessage(int timestamp, String message) {
            boolean answer = false;
            if (this.map.containsKey(message)) {
                int value = this.map.get(message);
                if (timestamp >= value + 10) {
                    answer = true;
                    this.map.put(message, timestamp);
                }
            } else {
                this.map.put(message, timestamp);
                answer = true;
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        boolean x, answer;

        Logger logger = new task_359().new Logger();

        answer = true;
        x = logger.shouldPrintMessage(0, "A");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
        assert answer == x : "Answer is different";

        answer = true;
        x = logger.shouldPrintMessage(0, "B");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
        assert answer == x : "Answer is different";

        answer = true;
        x = logger.shouldPrintMessage(0, "C");  // 3 < 11, return false
        assert answer == x : "Answer is different";

        answer = false;
        x = logger.shouldPrintMessage(0, "A");  // 8 < 12, return false
        assert answer == x : "Answer is different";

        answer = false;
        x = logger.shouldPrintMessage(0, "B"); // 10 < 11, return false
        assert answer == x : "Answer is different";

        answer = false;
        x = logger.shouldPrintMessage(0, "C"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
        assert answer == x : "Answer is different";

        answer = true;
        x = logger.shouldPrintMessage(11, "A"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
        assert answer == x : "Answer is different";

        answer = true;
        x = logger.shouldPrintMessage(11, "B"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
        assert answer == x : "Answer is different";

        answer = true;
        x = logger.shouldPrintMessage(11, "C"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
        assert answer == x : "Answer is different";

        answer = false;
        x = logger.shouldPrintMessage(11, "A"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
        assert answer == x : "Answer is different";



//        answer = true;
//        x = logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
//        assert answer == x : "Answer is different";
//
//        answer = true;
//        x = logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
//        assert answer == x : "Answer is different";
//
//        answer = false;
//        x = logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
//        assert answer == x : "Answer is different";
//
//        answer = false;
//        x = logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
//        assert answer == x : "Answer is different";
//
//        answer = false;
//        x = logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
//        assert answer == x : "Answer is different";
//
//        answer = true;
//        x = logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
//        assert answer == x : "Answer is different";

    }
}
