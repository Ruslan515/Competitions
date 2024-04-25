# https://contest.yandex.ru/contest/59541/problems/D

import sys
from typing import Dict, List


def main():
    n, k = list(map(int, sys.stdin.readline().split()))
    a = list(map(int, sys.stdin.readline().split()))
    answer = "NO"
    d = {}
    for i, v in enumerate(a):
        if v in d.keys():
            prev = d[v]
            diff = i - prev
            if diff <= k:
                answer = "YES"
                break
            else:
                d[v] = i
        else:
            d[v] = i

    sys.stdout.write(f"{answer}\n")


if __name__ == "__main__":
    main()
