import sys
def main():
    n = int(input())
    if n == 1:
        k = 3
        f = lambda x: " ".join(map(str, [x[0], x[1]]))
        set_points = {
            tuple(map(int, sys.stdin.readline().split()))
            for _ in range(n)
        }
        p1 = set_points.pop()
        x1, y1 = p1
        p2 = (x1 + 1, y1)
        p3 = (x1, y1 + 1)
        p4 = (x1 + 1, y1 + 1)
        answer = "\n".join(list(map(f, [p1, p2, p3, p4])))
        sys.stdout.write(f"{k}\n{answer}\n")
        return 0
    elif n == 2:
        f = lambda x: " ".join(map(str, [x[0], x[1]]))
        set_points = {
            tuple(map(int, sys.stdin.readline().split()))
            for _ in range(n)
        }
        k = 2
        p1 = set_points.pop()
        p2 = set_points.pop()
        x1, y1 = p1
        x2, y2 = p2
        if x1 == x2:
            diff = abs(y1 - y2)
            if x1 >= 0:
                x3, x4 = x1 - diff, x2 - diff
            else:
                x3, x4 = x1 + diff, x2 + diff
            y3, y4 = y1, y2
            p3 = (x3, y4)
            p4 = (x4, y4)
        elif y1 == y2:
            diff = abs(x1 - x2)
            if y1 >= 0:
                y3, y4 = y1 - diff, y2 - diff
            else:
                y3, y4 = y1 + diff, y2 + diff
            x3, x4 = x1, x2
            p3 = (x3, y4)
            p4 = (x4, y4)
        else:
            x3, y3 = x1, y2
            x4, y4 = x2, y1
            p3 = (x3, y3)
            p4 = (x4, y4)
        answer = "\n".join(list(map(f, [p3, p4])))
        sys.stdout.write(f"{k}\n{answer}\n")
        return 0


    points = set()

    for _ in range(n):
        x, y = map(int, input().split())
        points.add((x, y))

    points = list(points)
    missing_points = []
    answer = 10
    # for x1, y1 in points:
    #     label = False
    #     for x2, y2 in points:
    for i in range(n):
        p1 = points[i]
        x1, y1 = p1
        label = False
        for j in range(i + 1, n):
            p2 = points[j]
            x2, y2 = p2

            if x1 != x2 or y1 != y2:
                cx = (x1 + x2) / 2
                cy = (y1 + y2) / 2
                dx = (y2 - y1) / 2
                dy = (x1 - x2) / 2

                p1 = (int(cx + dx), int(cy + dy))
                p2 = (int(cx - dx), int(cy - dy))

                if p1 in points and p2 in points:
                    answer = 0
                    missing_points = []
                    label = True
                    break
                elif (p1 not in points and p2 in points) and answer > 1:
                    missing_points = [p1]
                    answer = 1
                elif (p1 in points and p2 not in points) and answer > 1:
                    missing_points = [p2]
                    answer = 1
                elif answer > 2 and len(missing_points) == 2:
                    missing_points = [p2, p1]
                    answer = 2
        if label:
            break

    missing_points = list(set(missing_points))

    if len(missing_points) == 0:
        print(0)
    else:
        print(len(missing_points))
        for x, y in missing_points:
            print(x, y)


if __name__ == '__main__':
    main()
