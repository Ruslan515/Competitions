# https://codeforces.com/contest/1703/problem/A
def main():
    t = int(input())
    answer = "\n".join(["YES" if input().lower() == "yes" else "NO" for _ in range(t)])
    print(answer)

if __name__ == "__main__":
    main()