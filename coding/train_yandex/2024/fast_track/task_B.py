import sys


def find_max_rect(points, s):
    xs = set(point[0] for point in points)  # уникальные значения x
    ys = set(point[1] for point in points)  # уникальные значения y
    max_rect = []  # координаты прямоугольника с наибольшим кол-вом точек
    max_count = -1  # число точек в наибольшем прямоугольнике
    for x1 in xs:
        for y1 in ys:
            for x2 in xs:
                if x2 < x1:
                    continue
                for y2 in ys:
                    if y2 < y1:
                        continue
                    area = abs(x2 - x1) * abs(y2 - y1)
                    if area == 0 or area > s:
                        continue
                    count = sum(
                        1
                        for point in points
                        if x1 <= point[0] <= x2 and y1 <= point[1] <= y2
                    )
                    if count > max_count:
                        max_count = count
                        max_rect = [(x1, y1), (x2, y2)]
    answer = [
        i + 1
        for i, point in enumerate(points)
        if max_rect[0][0] <= point[0] <= max_rect[1][0] and max_rect[0][1] <= point[1] <= max_rect[1][1]
    ]
    return len(answer), " ".join(map(str, answer))


def main():
    n, s = map(int, sys.stdin.readline().split())
    orders = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
    count, line = find_max_rect(orders, s)
    print(count)
    print(line)


if __name__ == '__main__':
    main()
