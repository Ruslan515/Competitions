# https://contest.yandex.ru/contest/59541/problems/E

import sys
from typing import Dict, List


def main():
    d = {}
    answer = set()
    for _ in range(3):
        _ = sys.stdin.readline()
        a = set(map(int, sys.stdin.readline().split()))
        for x in a:
            d[x] = d.get(x, 0) + 1
            if d[x] > 1:
                answer.add(x)
    answer = list(answer)
    answer.sort()
    answer = " ".join(map(str, answer))
    sys.stdout.write(f"{answer}\n")


if __name__ == "__main__":
    main()
