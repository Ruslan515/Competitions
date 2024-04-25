# https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        from collections import deque
        answer = ""
        n = len(num)
        if k == n:
            answer = "0"
            return answer
        # if k == 1:
        #     idx = 0
        #     max_val = -1
        #     for i in range(n):
        #         val = int(num[i])
        #         if val > max_val:
        #             idx = i
        #     for i in range(n):
        #         if i != idx:
        #             answer += num[i]
        #     return answer
        dq = deque(num)
        dq_ans = deque()
        i = 0
        while i < k:
            first = dq.popleft()
            second = dq.popleft()
            if first == second:
                dq_ans.append(first)
                dq_ans.append(second)
                dq.appendleft(first)
            else:
                min_num = min(first, second)
                dq.appendleft(min_num)
                i += 1
        while True and dq:
            x = dq.popleft()
            if x != "0":
                dq.appendleft(x)
                break

        if not dq:
            answer = "0"
            return answer
        while dq:
            answer += dq.popleft()

        return answer


def main():
    solve = Solution()

    num = "1122"
    k = 2
    answer = "11"
    assert answer == solve.removeKdigits(num, k)

    num = "112"
    k = 1
    answer = "11"
    assert answer == solve.removeKdigits(num, k)

    num = "1432219"
    k = 3
    answer = "1219"
    assert answer == solve.removeKdigits(num, k)

    num = "10200"
    k = 1
    answer = "200"
    assert answer == solve.removeKdigits(num, k)

    num = "10"
    k = 2
    answer = "0"
    assert answer == solve.removeKdigits(num, k)


if __name__ == "__main__":
    main()
