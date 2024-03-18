def main():
    N = int(input())
    temperatures = list(map(int, input().split()))

    # Предобработка: находим минимум и максимум для каждого диапазона
    min_temp = [float('inf')] * (2 * N + 1)
    max_temp = [float('-inf')] * (2 * N + 1)

    for i in range(2 * N + 1):
        if i == 0:
            min_temp[i] = max_temp[i] = temperatures[i]
        else:
            min_temp[i] = min(min_temp[i - 1], temperatures[i])
            max_temp[i] = max(max_temp[i - 1], temperatures[i])

    B = int(input())

    for _ in range(B):
        t_min, t_max, d_min, d_max = map(int, input().split())
        d_min = N + d_min
        d_max = N + d_max

        # Проверяем условия для показа объявления
        actual_min = min(min_temp[d_max], temperatures[d_min])
        actual_max = max(max_temp[d_max], temperatures[d_min])

        if t_min <= actual_max and t_max >= actual_min:
            print("yes")
        else:
            print("no")


if __name__ == '__main__':
    main()
