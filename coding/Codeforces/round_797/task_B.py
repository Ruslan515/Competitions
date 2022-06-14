# https://codeforces.com/contest/1690/problem/B

from math import inf

INF = (-1) * inf

def solving(a, b, n):
    c = []
    for i in range(n):
        if b[i] != 0:
            ans = a[i] - b[i]
        else:
            ans = INF
        c.append(ans)
    new_set = set(c)
    if len(new_set) == 1 and c[0] >= 0:
        ans = "YES"
    elif len(new_set) == 1 and INF in new_set:
        ans = "YES"
    elif len(new_set) == 2 and  INF in new_set:
        ans = "YES"
    else:
        ans = "NO"
    return ans

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        answer.append(solving(a, b, n))
    answer = "\n".join(answer)
    print(answer)

if __name__ == "__main__":
    main()
