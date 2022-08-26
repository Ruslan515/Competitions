from collections import defaultdict

def main():
    t = int(input())
    ans = []
    my_dict = defaultdict(str)
    list_j = []
    list_k = []
    for tt in range(t):
        k, j = map(int, input().split())
        list_j.append(j)
        list_k.append(k)
        if k not in list(my_dict.keys()):
            g = "a"
            c = "b"
            for kk in range(1, k):
                g = g + c + g
                c = chr(ord(c) + 1)
            my_dict[k] = g

    for tt in range(t):
        k = list_k[tt]
        j = list_j[tt]
        if j == 0:
            ans.append(0)
        else:
            g = my_dict[k]
            n = len(g)
            i = j
            jj = 0
            while (i + jj) < n and g[jj] == g[i + jj]:
                jj += 1
            ans.append(jj)

    print("\n".join(map(str, ans)))

if __name__ == "__main__":
    main()