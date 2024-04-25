# https://contest.yandex.ru/contest/59541/problems/C

import sys
from typing import Dict, List


def get_dict(a: List) -> Dict[int, int]:
    d = {}
    for ch in a:
        d[ch] = d.get(ch, 0) + 1
    return d


def main():
    n = int(sys.stdin.readline())
    if n == 1:
        sys.stdout.write('0\n')
        return
    a = list(map(int, sys.stdin.readline().split()))
    d = get_dict(a)
    keys = list(d.keys())
    cnt = len(keys)
    if cnt == 1:
        sys.stdout.write('0\n')
        return
    keys.sort()
    max_count = 0
    for i in range(1, cnt):
        k_current = keys[i]
        k_prev = keys[i - 1]
        diff = k_current - k_prev
        if diff == 1:
            v_current = d[k_current]
            v_prev = d[k_prev]
            v = v_current + v_prev
            max_count = max(max_count, v)
    if max_count == 0:
        answer = n - 1
    else:
        answer = n - max_count

    sys.stdout.write(str(answer) + "\n")


if __name__ == "__main__":
    main()
