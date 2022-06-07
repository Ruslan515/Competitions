# https://contest.yandex.ru/contest/27393/problems/D/

def main():
    a, b, c =  [int(input()) for _ in range(3)]

    if c < 0 or (a == 0 and c ** 2 - b != 0):
        print('NO SOLUTION')
    elif a == 0 and c ** 2 == b:
        print('MANY SOLUTIONS')
    elif (c ** 2 - b) % a == 0:
        print((c ** 2 - b) // a)

    # if c >= 0:
    #     if a == 0 and c**2 - b == 0:
    #         print("MANY SOLUTIONS")
    #     else:
    #         x = (c**2 - b) / a
    #         if x == int(x):
    #             print(int(x))
    #         else:
    #             print("NO SOLUTION")
    # elif a == 0 and c**2 - b != 0:
    #     print("NO SOLUTION")
    # else:
    #
    #     print("NO SOLUTION")

    return 0

if __name__ == "__main__":
    main()
