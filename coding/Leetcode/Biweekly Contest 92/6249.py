# https://leetcode.com/contest/biweekly-contest-89/problems/range-product-queries-of-powers/

class Solution:
    def numberOfCuts(self, n: int) -> int:
        answer = n
        if n == 1:
            answer = 0
        else:
            if n % 2 == 0:
                answer = n // 2
        return answer


def read_data():
    n = int(input())
    return n

# def check(answer):
#     expected = [256,128,2,4194304,16777216,512,131072,128,256,131072,8,524288,268435456,256,128,2,8192,32768,128,131072,16384,16,16384,4194304,128,256,16777216,32768,16384,512,512,512,4,4194304,16384,128,8192,256,512,4,64,256,147483634,16,512,128,1,8,512,512,268435456,16384,512,4,16777216]
#     for i, (a, e) in enumerate(zip(answer, expected)):
#         if a != e:
#             print(i, a, e)

def main():
    n = read_data()
    sol = Solution()
    # check(sol.numberOfCuts(n))
    print(sol.numberOfCuts(n))

if __name__ == "__main__":
    main()