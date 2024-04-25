# https://contest.yandex.ru/contest/59541/problems/A

import sys


def main():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    answer = set(sys.stdin.readline().split())
    for _ in range(n - 1):
        k = int(sys.stdin.readline())
        songs = set(sys.stdin.readline().split())
        answer = answer.intersection(songs)
    sys.stdout.write(str(len(answer)) + '\n')
    answer = " ".join(sorted(list(answer)))
    sys.stdout.write(answer + "\n")


if __name__ == "__main__":
    main()
