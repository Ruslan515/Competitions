# https://contest.yandex.ru/contest/59540/problems/C/
import sys


def main():
    n = map(int, sys.stdin.readline().split())
    lines = list(map(int, sys.stdin.readline().split()))
    max_lines = max(lines)
    sums = sum(lines)
    sums_without = sums - max_lines
    if sums_without < max_lines:
        answer = max_lines - sums_without
    else:
        answer = sums
    sys.stdout.write(str(answer) + "\n")


if __name__ == "__main__":
    main()
