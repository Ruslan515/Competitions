# https://codeforces.com/contest/1709/problem/B
def solving(arr, s, t):
    ans = 0
    if s < t:
        step = 1
    else:
        step = -1
    for i in range(s, t, step):
        u = arr[i] - arr[i + step]
        if u > 0:
            ans += u

    return ans

def main():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))

    left_to_right = []
    for i in range(n - 1):
        u = arr[i] - arr[i + 1]
        if u < 0:
            u = 0
        left_to_right.append(u)

    right_to_left = []
    for i in range(n - 1, 0, -1):
        u = arr[i] - arr[i - 1]
        if u < 0:
            u = 0
        right_to_left.append(u)

    right_to_left.reverse()

    answer = []
    for _ in range(m):
        s, t = map(int, input().split())
        s = s - 1
        t = t - 1
        if s < t:
            ans = sum(left_to_right[s: t])
        else:
            ans = sum(right_to_left[t: s])

        answer.append(ans)
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()