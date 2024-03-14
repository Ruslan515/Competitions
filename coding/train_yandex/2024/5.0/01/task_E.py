# https://contest.yandex.ru/contest/59539/problems/E/

def main():
    n, k, d = map(int, input().split())
    n_low = str(n) + "0"
    n_high = str(n) + "9"
    n_low_int = int(n_low)
    n_high_int = int(n_high)
    for x in range(n_low_int, n_high_int + 1):
        y = x % k
        if y == 0:
            d = "".join(["0" for _ in range(d - 1)])
            print(x, d, sep="")
            return
    print(-1)


if __name__ == '__main__':
    main()
