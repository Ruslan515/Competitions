# https://contest.yandex.ru/contest/59540/problems/D/
import sys
from collections import defaultdict
from typing import Dict, List


def get_count(dict_el: Dict[int, List[int]]) -> int:
    count: int = 0
    for row, list_el in dict_el.items():
        len_l = len(list_el)
        if len_l > 1:
            list_el.sort()
            for i in range(len_l - 1):
                diff = list_el[i + 1] - list_el[i]
                if diff == 1:
                    count += 1

    return count


def main():
    n = int(sys.stdin.readline())
    all_per = n * 4
    dict_rows = defaultdict(list)
    dict_cols = defaultdict(list)
    for _ in range(n):
        y, x = map(int, sys.stdin.readline().split())
        dict_rows[y].append(x)
        dict_cols[x].append(y)
    y = get_count(dict_cols)
    x = get_count(dict_rows)
    count = x + y

    count *= 2
    answer = all_per - count
    sys.stdout.write(str(answer) + "\n")


if __name__ == "__main__":
    main()
