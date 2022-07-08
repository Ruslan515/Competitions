# https://codeforces.com/contest/1701/problem/A

def solving(arr):
    ans = 0
    sum_arr = sum([sum(arr[i]) for i in range(2)])
    if sum_arr == 0:
        ans = 0
    elif 1 <= sum_arr <= 3:
        ans = 1
    else:
        ans = 2
    return ans

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        arr = [list(map(int, input().split())) for _ in range(2)]
        answer.append(solving(arr))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()