# https://leetcode.com/contest/biweekly-contest-92/problems/minimum-penalty-for-a-shop/

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        from collections import Counter
        answer = 0
        cust_cnt = Counter(customers)
        if cust_cnt["Y"] == len(customers):
            answer = len(customers)
        elif cust_cnt["N"] == len(customers):
            answer = 0
        else:
            minimum_penalty = cust_cnt["Y"]
            penalty = minimum_penalty
            idx = -1
            for i in range(0, len(customers)):
                if customers[i] == "Y":
                    penalty -= 1
                else:
                    penalty += 1
                if penalty < minimum_penalty:
                    minimum_penalty = penalty
                    idx = i
            answer = idx + 1
        return answer


def read_data():
    customers = input()
    return customers

def main():
    customers = read_data()
    sol = Solution()
    # check(sol.numberOfCuts(n))
    print(sol.bestClosingTime(customers))

if __name__ == "__main__":
    main()