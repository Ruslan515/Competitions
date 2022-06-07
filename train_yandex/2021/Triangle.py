# https://contest.yandex.ru/contest/27393/problems/B/
a = int(input())
b = int(input())
c = int(input())

sum_ab = a + b
sum_ac = a + c
sum_bc = b + c

if (sum_ab <= c) or (sum_bc <= a) or (sum_ac <= b):
    print("NO")
else:
    print("YES")