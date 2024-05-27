import sys


def min_pseudorange(s):
    n = len(s)
    s.sort()  # Сортируем множество по возрастанию
    start = 0
    end = n // 2

    answer = s[start: end]
    min_a = answer[0]
    max_a = answer[- 1]
    lambda_a = (max_a - min_a) / (s[n - 1] - s[end])

    min_a = s[end]
    max_a = s[n - 1]
    t = (max_a - min_a) / (s[end - 1] - s[start])
    if t < lambda_a:
        lambda_a = t
        answer = s[end:]

    min_without = s[0]
    max_without = s[n - 1]
    x = max_without - min_without

    for _ in range(1, n // 2):
        start += 1
        end += 1

        min_a = s[start]
        max_a = s[end - 1]
        t = (max_a - min_a)
        t = t / x
        if t < lambda_a:
            lambda_a = t
            answer = s[start: end]

    return lambda_a, answer


def main():
    # Пример ввода
    n = int(sys.stdin.readline())
    s = list(map(int, sys.stdin.readline().split()))

    # Решение
    lambda_val, A = min_pseudorange(s)
    print(f"{lambda_val:.8f}")
    print(" ".join(map(str, A)))


if __name__ == '__main__':
    main()
