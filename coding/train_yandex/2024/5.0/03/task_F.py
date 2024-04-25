# https://contest.yandex.ru/contest/59541/problems/F

import sys
from typing import Dict, List


def main():
    words_set = set(sys.stdin.readline().split())
    words = list(sys.stdin.readline().split())
    lens_set = list(
        set(
            len(word)
            for word in words_set
        )
    )
    lens_set.sort()

    answer = []
    for word in words:
        label = False
        for len_word in lens_set:
            slice = word[:len_word]
            if slice in words_set:
                answer.append(slice)
                label = True
                break
        if not label:
            answer.append(word)
    answer = " ".join(answer)
    sys.stdout.write(f"{answer}\n")


if __name__ == "__main__":
    main()
