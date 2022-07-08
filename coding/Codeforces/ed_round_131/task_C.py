# не решено
# https://codeforces.com/contest/1701/problem/C
# 1
# 3 13
# 1 1 1 1 1 1 2 2 2 2 3 3 3

# 1
# 3 6
# 1 1 1 1 1 1

# 1
# 1 1
# 1

# 1
# 1 2
# 1 1

# 1
# 4 6
# 1 1 1 1 1 1

from collections import defaultdict

def solving(n, m, arr):
    ans = 0
    d = defaultdict(int)
    for i in range(n):
        d[i + 1] = 0
    for a in arr:
        d[a] += 1
    min_a = min(d.values())
    max_a = max(d.values())
    if min_a == max_a:
        ans = min_a
    else:
        new_list = [i for i in range(min_a, max_a + 1)]
        len_new_list = len(new_list)
        if len_new_list % 2 == 0:
            idx = len_new_list // 2
        else:
            idx = len_new_list // 2 + 1
        ans = new_list[idx]
    # print(ans)
    return ans

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        n, m = map(int, input().split())
        arr = list(map(int, input().split()))
        answer.append(solving(n, m, arr))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()