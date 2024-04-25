# https://contest.yandex.ru/contest/59540/problems/B/
import sys


def main():
    n, k = map(int, sys.stdin.readline().split())
    prices = list(map(int, sys.stdin.readline().split()))
    max_diff = 0
    i = 0
    while i < n - 1:
        j = i + 1
        curr_price = prices[i]
        while j < n and j <= i + k:
            diff = prices[j] - curr_price
            max_diff = max(max_diff, diff)
            j += 1
        i += 1
    sys.stdout.write(str(max_diff))


if __name__ == "__main__":
    main()
