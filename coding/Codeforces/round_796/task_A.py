# https://codeforces.com/contest/1688/problem/0

def solving(x):
    bin_x = "{0:b}".format(x)
    n = len(bin_x)
    bin_y = ["0" for _ in range(n)]
    if x == 1 or x == 2:
        return 3

    for i, d in enumerate(bin_x[::-1]):
        if d == "1":
            bin_y[n - i - 1] = d
            break

    if (x & (x - 1) == 0):
        bin_y[-1] = "1"
    bin_y = "".join(bin_y)
    y = int(bin_y, 2)
    return y

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        x = int(input())
        answer.append(solving(x))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()
