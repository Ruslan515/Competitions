DAY_H = 60 * 60 * 24


def parse_time(time_str):
    return list(map(int, time_str.split(":")))


def time_to_seconds(h, m, s):
    answer = h * 3600 + m * 60 + s
    if answer == 0:
        answer = DAY_H
    return answer


def main():
    N = int(input().strip())
    events = []

    for _ in range(N):
        times = input().strip()
        open_time, close_time = times.split('-')
        open_seconds = time_to_seconds(*parse_time(open_time))
        close_seconds = time_to_seconds(*parse_time(close_time))

        if close_seconds < open_seconds:
            # Пересекает полуночь
            events.append((open_seconds, 1))  # Открытие
            events.append((86400, -1))  # Закрытие на конец дня
            events.append((0, 1))  # Открытие на начало дня
            events.append((close_seconds, -1))  # Закрытие после полуночи
        else:
            events.append((open_seconds, 1))  # Открытие
            events.append((close_seconds, -1))  # Закрытие

    # Сортировка событий
    events.sort()

    # Обработка событий
    current_active = 0
    max_active = 0

    for time, change in events:
        current_active += change
        if current_active > max_active:
            max_active = current_active

    print(max_active)


if __name__ == '__main__':
    main()
