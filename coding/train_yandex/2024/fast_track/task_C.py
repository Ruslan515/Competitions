import sys


def main():
    n = int(sys.stdin.readline())
    temps = list(map(int, sys.stdin.readline().split()))
    b = int(sys.stdin.readline())
    ans = []
    for _ in range(b):
        t_min, t_max, d_min, d_max = list(map(int, sys.stdin.readline().split()))
        left = n + d_min
        right = n + d_max
        min_temp = 10 ** 9 + 1
        max_temp = (-1) * min_temp
        for temp in temps[left:right + 1]:
            min_temp = min(min_temp, temp)
            max_temp = max(max_temp, temp)
        low = t_min > max_temp
        high = min_temp > t_max
        if low or high:
            ans.append("no")
            # sys.stdout.write("no\n")
        else:
            ans.append("yes")
            # sys.stdout.write("yes\n")

    sys.stdout.write("\n".join(ans))

if __name__ == '__main__':
    main()
