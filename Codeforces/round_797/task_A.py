# https://codeforces.com/contest/1690/problem/A

from math import ceil

def solving(n):
    h1 = ceil(n / 3) + 1
    h2 = h1 - 1
    h3 = n - (h1 + h2)
    if h3 == 0:
        h3 = 1
        h2 = h2 -1
    return h2, h1, h3

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        n = int(input())
        h2, h1, h3 = solving(n)
        ans = " ".join(map(str, [h2, h1, h3]))
        answer.append(ans)
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()
