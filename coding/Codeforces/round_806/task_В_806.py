# https://codeforces.com/contest/1703/problem/B
from collections import Counter

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        sum_ans = 0
        n = int(input())
        s = input()
        c = Counter(s)
        for key, value in c.items():
            if value > 1:
                sum_ans += (value + 1)
            else:
                sum_ans += 2
        answer.append(sum_ans)
    answer = "\n".join(map(str, answer))

    print(answer)

if __name__ == "__main__":
    main()