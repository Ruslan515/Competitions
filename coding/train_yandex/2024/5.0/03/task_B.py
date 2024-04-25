# https://contest.yandex.ru/contest/59541/problems/B/

import sys
from typing import Dict


def get_dict(s: str) -> Dict[str, int]:
    d = {}
    for ch in s:
        d[ch] = d.get(ch, 0) + 1
    return d


def main():
    s1 = sys.stdin.readline()
    s2 = sys.stdin.readline()
    d1, d2 = get_dict(s1), get_dict(s2)
    if d1 == d2:
        answer = "YES"
    else:
        answer = "NO"
    sys.stdout.write(answer + "\n")


if __name__ == "__main__":
    main()
