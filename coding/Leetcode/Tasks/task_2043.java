//https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26
package leetcode.tasks;

import java.util.Map;
import java.util.HashMap;

public class task_2043 {
    class Bank {
        Map<Integer, Long> balanceMap;

        public Bank(long[] balance) {
            balanceMap = new HashMap<>();
            for (int i = 0; i < balance.length; i++) {
                balanceMap.put(i + 1, balance[i]);
            }
        }

        public boolean transfer(int account1, int account2, long money) {
            boolean answer = false;
            if (!this.balanceMap.containsKey(account1) || !this.balanceMap.containsKey(account2)) {
                return answer;
            }
            long balance1 = this.balanceMap.get(account1);
            if (money <= balance1) {
                this.balanceMap.put(account1, balance1 - money);
                this.balanceMap.put(account2, this.balanceMap.get(account2) + money);
                answer = true;
            }

            return answer;
        }

        public boolean deposit(int account, long money) {
            boolean answer = false;
            if (!this.balanceMap.containsKey(account)) {

                return answer;
            }
            answer = true;
            this.balanceMap.put(account, this.balanceMap.get(account) + money);

            return answer;

        }

        public boolean withdraw(int account, long money) {
            boolean answer = false;
            if (!this.balanceMap.containsKey(account) || this.balanceMap.get(account) < money) {
                return answer;
            }
            answer = true;
            this.balanceMap.put(account, this.balanceMap.get(account) - money);

            return answer;

        }
    }

    public void main(String[] args) {

        boolean answer;

        Bank bank = new Bank(new long[]{10, 100, 20, 50, 30});

        answer = true;
        assert answer == bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
        // Account 3 has $20 - $10 = $10.

        answer = true;
        assert answer == bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
        // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.

        answer = true;
        assert answer == bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
        // Account 5 has $10 + $20 = $30.

        answer = false;
        assert answer == bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
        // so it is invalid to transfer $15 from it.

        answer = false;
        assert answer == bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
    }

}
