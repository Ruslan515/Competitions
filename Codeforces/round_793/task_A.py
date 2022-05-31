
def solving(s, n):
    if (n == 2 and s[0] == s[1]):
        return 2
    if (n % 2 == 0):
        i = n // 2 - 2
        start_char = s[i]
        j = n // 2 + 1
        count = 2
    else:
        start_char = s[n // 2]
        i = n // 2 - 1
        j = n // 2 + 1
        count = 1

    while (i >= 0 and j < n and s[i] == s[j] and s[i] == start_char):
        i -= 1
        j += 1
        count += 2

    return count




t = int(input())
inp = []
inp_n = []
for i in range(t):
    inp_n.append(int(input()))
    inp.append(input())

for i in range(t):
    print(solving(inp[i], inp_n[i]))