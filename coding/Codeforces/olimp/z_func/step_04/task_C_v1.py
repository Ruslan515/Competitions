# https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/C
def z_func(s):
    n = len(s)
    z = [0] * n
    temp = [1] * (n + 1)
    l = 0
    r = 0
    for i in range(1, n):
        if r >= i:
            z[i] = (min(z[i - l], r - i + 1))
            for step in range(1, z[i] + 1):
                temp[step] += 1
        while z[i] + i < n and s[z[i]] == s[z[i] + i]:
            z[i] += 1
            temp[z[i]] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1

    print(" ".join(map(str, temp[1:])))
    return

def main():
    q = int(input())
    for _ in range(q):
        s = input()
        z_func(s)
    return

if __name__ == "__main__":
    main()
