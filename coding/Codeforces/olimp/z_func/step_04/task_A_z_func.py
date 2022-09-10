# https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/A
def solving(s):
    n = len(s)
    z = [0]*n
    l = 0
    r = 0
    answer = s
    for i in range(1, n):
        if r >= i:
            z[i] = (min(z[i - l], r - i + 1))
        while z[i] + i < n and s[z[i]] == s[z[i] + i]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
        if z[i] + i == n:
            answer = s[:i]
            break
    print(answer)

    return

def main():
    t = int(input())
    for _ in range(t):
        s = input()
        solving(s)
    return

if __name__ == "__main__":
    main()
