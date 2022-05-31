# https://codeforces.com/contest/1691/problem/A
def main():
    t = int(input())
    ans = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        my_dict = {}
        my_dict["odd"] = 0
        my_dict["even"] = 0
        for el in a:
            if el % 2 == 0:
                my_dict["even"] += 1
            else:
                my_dict["odd"] += 1
        if my_dict["odd"] == 0 or my_dict["even"] == 0:
            ans.append(0)
        else:
            ans.append(min(my_dict["odd"], my_dict["even"]))

    new_ans = "\n".join(list(map(str, ans)))
    print(new_ans)


if __name__ == "__main__":
    main()

