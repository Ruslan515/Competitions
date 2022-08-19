# https://codeforces.com/contest/1720/problem/B

def solving(a, n):
    beauty = 0
    for l in range(n - 1):
        for r in range(l + 1, n):
            without_a = a[:l] + a[r:]
            with_a = a[l: r]
            max_without = max(without_a)
            min_without = min(without_a)
            max_with = max(with_a)
            min_with = min(with_a)
            temp = max_without - min_without + max_with - min_with
            if temp > beauty:
                beauty = temp
    return beauty

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        answer.append(solving(a, n))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()
