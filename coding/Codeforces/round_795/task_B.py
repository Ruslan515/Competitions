# https://codeforces.com/contest/1691/problem/B
"""
1
6
1 1 1 2 2 2
"""
from collections import Counter

def main():
    t = int(input())
    ans = []
    for _ in range(t):
        n = int(input())
        s = Counter(map(int, input().split()))
        label = True
        for value in s.values():
            if value == 1:
                label = False
                break
        if label or len(s) == 1:
            ans_list = []
            smesh = 0
            for i, key in enumerate(sorted(s.keys())):
                temp = [j + 1 for j in range(smesh, smesh + s[key])]
                temp.reverse()
                if len(temp) % 2 != 0:
                    x = temp[0]
                    idx = len(temp) // 2
                    temp[0] = temp[idx]
                    temp[idx] = x
                ans_list += temp
                smesh += s[key]
            ans.append(" ".join(map(str, ans_list)))
        else:
            ans.append(f"-1")

    print("\n".join(ans))

if __name__ == "__main__":
    main()
