"""
4
23:59:59-00:00:00
00:00:00-00:00:00
02:59:59-05:00:00
03:59:59-04:00:00
"""
DAY_H = 60 * 60 * 24


def convert(time: str) -> int:
    answer = 0
    hh, mm, ss = list(map(int, time.split(':')))
    answer = hh * 3600 + mm * 60 + ss
    return answer


def main():
    n = int(input())
    pvz = []
    for i in range(n):
        start_time, end_time = list(
            map(
                convert,
                input().split("-")
            )
        )

        if end_time <= start_time:
            end_time += DAY_H

        pvz.append([start_time, end_time])

    pvz.sort(key=lambda x: x[0])
    merged = []
    for interval in pvz:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])

    count = len(merged)
    answer = n - count + 1
    print(answer)


if __name__ == '__main__':
    main()
