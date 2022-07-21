# https://codeforces.com/contest/1709/problem/C
from collections import Counter
def solving(psp):
    my_dict = Counter(psp)
    if my_dict["?"] == 0 or my_dict["?"] == 2:
        ans = "YES"
    else:
        sum1 = abs(my_dict["("] - my_dict[")"])
        sum2 = sum1 - my_dict["?"]
        if sum2 == 0:
            ans = "YES"
        else:
            ans = "NO"


    return ans

def main():
    t = int(input())
    answer = []
    for _ in range(t):
        psp = input()
        answer.append(solving(psp))
    answer = "\n".join(map(str, answer))
    print(answer)

if __name__ == "__main__":
    main()