# https://contest.yandex.ru/contest/59541/problems/G

import sys
from typing import Dict, List


def main():
    n = int(sys.stdin.readline())
    f = lambda x: " ".join(map(str, [x[0], x[1]]))
    set_points = {
        tuple(map(int, sys.stdin.readline().split()))
        for _ in range(n)
    }
    if n == 1:
        k = 3
        p1 = set_points.pop()
        x1, y1 = p1
        p2 = (x1 + 1, y1)
        p3 = (x1, y1 + 1)
        p4 = (x1 + 1, y1 + 1)
        answer = "\n".join(list(map(f, [p1, p2, p3, p4])))
        sys.stdout.write(f"{k}\n{answer}\n")
        return 0
    elif n == 2:
        k = 2
        p1 = set_points.pop()
        p2 = set_points.pop()
        x1, y1 = p1
        x2, y2 = p2
        if x1 == x2:
            diff = abs(y1 - y2)
            if x1 >= 0:
                x3, x4 = x1 - diff, x2 - diff
            else:
                x3, x4 = x1 + diff, x2 + diff
            y3, y4 = y1, y2
            p3 = (x3, y4)
            p4 = (x4, y4)
        elif y1 == y2:
            diff = abs(x1 - x2)
            if y1 >= 0:
                y3, y4 = y1 - diff, y2 - diff
            else:
                y3, y4 = y1 + diff, y2 + diff
            x3, x4 = x1, x2
            p3 = (x3, y4)
            p4 = (x4, y4)
        else:
            x3, y3 = x1, y2
            x4, y4 = x2, y1
            p3 = (x3, y3)
            p4 = (x4, y4)
        answer = "\n".join(list(map(f, [p3, p4])))
        sys.stdout.write(f"{k}\n{answer}\n")
        return 0

    k = n + 1
    answer = []
    list_points = list(set_points)
    for i in range(n):
        p1 = list_points[i]
        x1, y1 = p1
        label = False
        for j in range(i + 1, n):
            p2 = list_points[j]
            x2, y2 = p2
            if x1 == x2 or y1 == y2:
                continue
            x3, y3 = x1, y2
            x4, y4 = x2, y1
            p3 = (x3, y3)
            p4 = (x4, y4)
            if p3 in set_points and p4 in set_points:
                k = 0
                answer = []
                label = True
            elif (p3 in set_points and p4 not in list_points) and k > 1:
                k = 1
                answer = [p4]
            elif (p4 in set_points and p3 not in list_points) and k > 1:
                k = 1
                answer = [p3]
            else:
                k = 2
                answer = [p3, p4]
        if label:
            break

    answer = "\n".join(list(map(f, answer)))
    sys.stdout.write(f"{k}\n{answer}\n")


if __name__ == "__main__":
    main()
