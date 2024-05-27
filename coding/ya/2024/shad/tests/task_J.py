import sys


def min_pseudorange(s):
    n = len(s)
    s.sort()  # Сортируем множество по возрастанию
    a = s[n // 4:(n // 4) * 3]
    diam_a = max(a) - min(a)
    diam_b = max(s) - min(s)

    lambda_val = diam_a / diam_b  # Вычисляем псевдоразмах

    return lambda_val, a


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
