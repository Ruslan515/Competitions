import math

n, m = map(int, input().split())
a = list(map(int, input().split()))
lf = [0]
lb = [0]
for k in range(n - 1):
    lf.append(lf[k] + max(a[k] - a[k + 1], 0))
    lb.append(lb[k] + max(a[k + 1] - a[k], 0))

for j in range(m):
    s, t = map(int, input().split())
    if t > s:
        print(lf[t - 1] - lf[s - 1])
    else:
        print(lb[s - 1] - lb[t - 1])