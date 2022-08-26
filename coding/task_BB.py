
def main():
    t = int(input())
    ans = []
    for tt in range(t):
        k, j = map(int, input().split())
        if j == 0:
            ans.append(0)
        else:
            g = "a"
            c = "b"
            for kk in range(1, k):
                g = g + c + g
                c = chr(ord(c) + 1)
            n = len(g)
            i = j
            jj = 0
            while (i + jj) < n and g[jj] == g[i + jj]:
                jj += 1
            ans.append(jj)

    print("\n".join(map(str, ans)))

if __name__ == "__main__":
    main()