# https://codeforces.com/contest/1689/problem/0

from collections import Counter

def solving(a, b, n, m, k):
    dict_a = Counter(a)
    dict_b = Counter(b)
    set_all = set(a)
    set_b = set(b)
    set_all.update(set_b)
    c = ""
    label = True
    while label:
        temp_k = k
        while temp_k != 0:
            min_char = min(set_all)
            sum_all_dict = 0
            if min_char in dict_a:
                min_c = min(dict_a[min_char], k)
                c += min_char * min_c
                dict_a[min_char] -= min_c
                sum_all_dict = sum(dict_a.values())
            else:
                min_c = min(dict_b[min_char], k)
                c += min_char * min_c
                dict_b[min_char] -= min_c
                sum_all_dict = sum(dict_b.values())
            if sum_all_dict == 0:
                label = True
                break
    return c


def main():
    t = int(input())
    answer = []
    for _ in range(t):
        n, m, k = map(int, input().split())
        a = input()
        b = input()
        answer.append(solving(a, b, n, m, k))
    answer = "\n".join(answer)
    print(answer)

if __name__ == "__main__":
    main()
