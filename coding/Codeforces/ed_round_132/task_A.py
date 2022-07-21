# https://codeforces.com/contest/1709/problem/A
def solving(arr, x):
    i = 0
    while True:
        y = arr[x]
        if y == 0 and i != 2:
            ans = "NO"
            break
        elif y == 0 and i == 2:
            ans = "YES"
            break
        else:
            x = y - 1
            i += 1

    return ans

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        x = int(input()) - 1
        arr = list(map(int, input().split()))
        answer.append(solving(arr, x))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()