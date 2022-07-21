# https://codeforces.com/contest/1709/problem/C
import sys
input=sys.stdin.readline
for _ in range(int(input())):
    string=tuple(input().strip())
    n=len(string)
    counter=variables=0
    open=n//2-string.count("(")
    close=n//2-string.count(")")
    for i in range(n):
            if string[i]=="(" or i==0:
                counter+=1
            elif string[i]==")" or i==n-1:
                counter-=1
            else:
                variables+=1
            if counter+variables<=1:
                open-=variables
                counter+=variables
                variables=0
    print("YES" if (variables+counter==0) or (counter-variables==0)else "NO")