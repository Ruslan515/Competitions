# https://leetcode.com/contest/biweekly-contest-89/problems/range-product-queries-of-powers/

class Solution:
    def two_powers(self, num):
        return [1 << idx for idx in range(num.bit_length()) if num & (1 << idx)]

    def productQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        powers = self.two_powers(n)
        answer = []
        # powers = []
        # power_2 = 1
        # powers.append(power_2)
        # sum_power_2 = power_2
        # while sum_power_2 != n:
        #     power_2 *= 2
        #     powers.append(power_2)
        #     sum_power_2 += power_2
        for i in range(len(queries)):
            query = queries[i]
            # 42
            # 2147483648
            # 147483634
            left = query[0]
            right = query[1]
            prod = 1
            for i in range(left, right + 1):
                prod *= powers[i]
            answer.append(prod % (10**9 + 7))

        return answer


def read_data():
    n = int(input())
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    queries = [list(map(int, el.split(","))) for el in s]
    return n, queries

def check(answer):
    expected = [256,128,2,4194304,16777216,512,131072,128,256,131072,8,524288,268435456,256,128,2,8192,32768,128,131072,16384,16,16384,4194304,128,256,16777216,32768,16384,512,512,512,4,4194304,16384,128,8192,256,512,4,64,256,147483634,16,512,128,1,8,512,512,268435456,16384,512,4,16777216]
    for i, (a, e) in enumerate(zip(answer, expected)):
        if a != e:
            print(i, a, e)

def main():
    n, queries = read_data()
    sol = Solution()
    check(sol.productQueries(n, queries))
    # print(sol.productQueries(n, queries))

if __name__ == "__main__":
    main()