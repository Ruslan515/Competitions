from itertools import combinations


def diam(subset):
    return max(subset) - min(subset)


def lambda_value(A, S):
    return diam(A) / diam(S - A)


def main():
    # Чтение входных данных
    N = int(input())
    S = set(map(int, input().split()))

    # Сортировка множества S
    sorted_S = sorted(S)

    # Инициализация минимального значения λ(A, S) и соответствующего подмножества A
    min_lambda = float('inf')
    min_subset = None

    # Перебор всех возможных подмножеств A размера |S|/2
    for A in combinations(sorted_S, N // 2):
        A = set(A)
        lambda_val = lambda_value(A, S)
        if lambda_val < min_lambda:
            min_lambda = lambda_val
            min_subset = A

    # Вывод результата
    print(min_lambda)
    print(*min_subset)


if __name__ == '__main__':
    main()
