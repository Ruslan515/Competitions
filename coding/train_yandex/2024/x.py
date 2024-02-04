n, m = map(int, input().split())
hours = [str(i).zfill(len(str(n-1))) for i in range(n)]
minutes = [str(i).zfill(len(str(m-1))) for i in range(m)]
palindromes = 0
for hour in hours:
    if hour[::-1] in minutes:
        palindromes += 1
print(palindromes)