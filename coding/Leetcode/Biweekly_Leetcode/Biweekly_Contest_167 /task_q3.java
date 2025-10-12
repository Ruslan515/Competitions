// https://leetcode.com/problems/design-exam-scores-tracker/
package leetcode.bw.bw_167;

import java.util.ArrayList;
import java.util.*;

public class task_q3 {


    class ExamTracker {
        private List<Integer> times;
        private List<Long> prefixSums;
        private int[] lastRecords;

        public ExamTracker() {
            times = new ArrayList<>();
            prefixSums = new ArrayList<>();
        }

        public void record(int time, int score) {
            lastRecords = new int[]{time, score};

            times.add(lastRecords[0]);

            if (prefixSums.isEmpty()) {
                prefixSums.add((long) lastRecords[1]);
            } else {
                long lastSum = prefixSums.get(prefixSums.size() - 1);
                prefixSums.add(lastSum + lastRecords[1]);
            }
        }

        public long totalScore(int startTime, int endTime) {
            if (times.isEmpty()) {
                return 0;
            }

            int leftIndex = lowerBound(times, startTime);
            int rightIndex = upperBound(times, endTime) - 1;

            if (leftIndex > rightIndex) {
                return 0;
            }

            if (leftIndex == 0) {
                return prefixSums.get(rightIndex);
            } else {
                return prefixSums.get(rightIndex) - prefixSums.get(leftIndex - 1);
            }
        }

        private int lowerBound(List<Integer> list, int target) {
            int low = 0;
            int high = list.size() - 1;
            int answer = list.size();

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (list.get(mid) < target) {
                    low = mid + 1;
                } else {
                    answer = mid;
                    high = mid - 1;
                }
            }
            return answer;
        }

        private int upperBound(List<Integer> list, int target) {
            int low = 0;
            int high = list.size() - 1;
            int answer = list.size();

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (list.get(mid) <= target) {
                    low = mid + 1;
                } else {
                    answer = mid;
                    high = mid - 1;
                }
            }
            return answer;
        }
    }
//    class ExamTracker {
//        ArrayList<Integer> times;
//        ArrayList<Long> prefix_sums;
//
//        public ExamTracker() {
//            this.times = new ArrayList<>();
//            this.prefix_sums = new ArrayList<>();
//        }
//
//        public void record(int time, int score) {
//            this.times.add(time);
//            if (prefix_sums.size() == 0) {
//                prefix_sums.add((long) score);
//            } else {
//                prefix_sums.add(prefix_sums.get(prefix_sums.size() - 1) + (long) score);
//            }
//        }
//
//        public int lower_bound(int target) {
//            int low = 0;
//            int high = this.times.size() - 1;
//            int result = this.times.size();
//            while (low <= high) {
//                int mid = (low + high) / 2;
//                if (this.times.get(mid) < target) {
//                    low = mid + 1;
//                } else {
//                    result = mid;
//                    high = mid - 1;
//                }
//            }
//
//            return result;
//        }
//
//        public int upper_bound(int target) {
//            int low = 0;
//            int high = this.times.size() - 1;
//            int result = this.times.size();
//            while (low <= high) {
//                int mid = (low + high) / 2;
//                if (this.times.get(mid) <= target) {
//                    low = mid + 1;
//                } else {
//                    result = mid;
//                    high = mid - 1;
//                }
//            }
//
//            return result;
//        }
//
//        public long totalScore(int startTime, int endTime) {
//            long answer = 0;
//            if (this.times.size() == 0) {
//                return answer;
//            }
//            int left_index = lower_bound(startTime);
//            int right_index = upper_bound(endTime);
//            if (left_index > right_index) {
//                return answer;
//            }
//            if (left_index == 0) {
//                answer = this.prefix_sums.get(right_index);
//            } else {
//                answer = this.prefix_sums.get(right_index) - this.prefix_sums.get(left_index - 1);
//            }
//
//            return answer;
//        }
//    }

    /**
     * Your ExamTracker object will be instantiated and called as such:
     * ExamTracker obj = new ExamTracker();
     * obj.record(time,score);
     * long param_2 = obj.totalScore(startTime,endTime);
     */

    public void main(String[] args) {
        long answer;

        ExamTracker examTracker = new ExamTracker();

        examTracker.record(1, 98); // Alice takes a new exam at time 1, scoring 98.
        assert 98 == examTracker.totalScore(1, 1); // Between time 1 and time 1, Alice took 1 exam at time 1, scoring 98. The total score is 98.
        examTracker.record(5, 99); // Alice takes a new exam at time 5, scoring 99.
        assert 98 == examTracker.totalScore(1, 3); // Between time 1 and time 3, Alice took 1 exam at time 1, scoring 98. The total score is 98.
        assert 197 == examTracker.totalScore(1, 5); // Between time 1 and time 5, Alice took 2 exams at time 1 and 5, scoring 98 and 99. The total score is 98 + 99 = 197.
        assert 0 == examTracker.totalScore(3, 4); // Alice did not take any exam between time 3 and time 4. Therefore, the answer is 0.
        assert 99 == examTracker.totalScore(2, 5); // Between time 2 and time 5, Alice took 1 exam at time 5, scoring 99. The total score is 99.

    }

}
