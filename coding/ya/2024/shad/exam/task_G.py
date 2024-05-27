def calculate_position_and_velocity(intervals):
    results = []
    x = 0
    v = 0
    for l, r, a in intervals:
        dt = r - l
        # x(t) = x + v*t + 0.5*a*t^2
        # v(t) = v + a*t
        new_x = x + v * dt + 0.5 * a * dt * dt
        new_v = v + a * dt
        results.append((new_x, new_v))
        x = new_x
        v = new_v
    return results


def find_time_for_distance(d, intervals, results):
    # Бинарный поиск по результатам для нахождения нужного интервала
    lo, hi = 0, len(results)
    while lo < hi:
        mid = (lo + hi) // 2
        if results[mid][0] < d:
            lo = mid + 1
        else:
            hi = mid

    # Теперь lo указывает на первый интервал, где x >= d
    if lo == 0:
        return None  # Недостижимо

    # Рассчитываем точное время в найденном интервале
    l, r, a = intervals[lo - 1]
    x_prev, v_prev = results[lo - 1] if lo > 0 else (0, 0)
    if a == 0:
        # Линейное движение: x(t) = x_prev + v_prev * (t - l)
        time = l + (d - x_prev) / v_prev
    else:
        # Квадратичное движение: x(t) = x_prev + v_prev * (t - l) + 0.5 * a * (t - l)^2
        # Решаем квадратное уравнение относительно t
        A = 0.5 * a
        B = v_prev
        C = x_prev - d
        delta = B ** 2 - 4 * A * C
        sqrt_delta = delta ** 0.5
        t1 = (-B + sqrt_delta) / (2 * A)
        t2 = (-B - sqrt_delta) / (2 * A)
        time = min(t1, t2) + l

    return int(time)

def main():
    # Чтение данных
    n = int(input())
    intervals = []
    for _ in range(n):
        l, r, a = map(int, input().split())
        intervals.append((l, r, a))

    q = int(input())
    distances = [int(input()) for _ in range(q)]

    # Вычисление позиций и скоростей на концах интервалов
    results = calculate_position_and_velocity(intervals)

    # Обработка запросов на расстояние
    for d in distances:
        print(find_time_for_distance(d, intervals, results))

if __name__ == '__main__':
    main()
