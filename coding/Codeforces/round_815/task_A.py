# https://codeforces.com/contest/1720/problem/A

def solving(a, b, c, d):
    if (a == 0 and c != 0) or (a != 0 and c == 0):
        return 1
    elif (a == 0 and c == 0) or (a / c == b / d):
        return 0
    elif (
            ((a / c) / (b / d) == int((a / c) / (b / d))) or
            ((c / a) / (d / b) == int((c / a) / (d / b)))):
        return 1
    else:
        return 2

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        a, b, c, d = map(int, input().split())
        answer.append(solving(a, b, c, d))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()
