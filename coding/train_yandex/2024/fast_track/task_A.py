import sys


# [1, 2, 3, [5, 5], 6, [7, 8, 9, [10, 11]]]
# [[[[[[1]]]], []]]
# [0, 10, 2, 5, -999999999]

def main():
    line = sys.stdin.readline()
    for symb in ["[", "]"]:
        line = line.replace(symb, "")
    line = "".join(line.split())
    a = [
        int(x)
        for x in line.split(",")
        if x != ""
    ]
    d = {}
    max_val = -1
    ans = []
    for x in a:
        d[x] = d.get(x, 0) + 1
        if d[x] > max_val:
            ans = [x]
            max_val = d[x]
        elif d[x] == max_val:
            ans.append(x)
    ans.sort()
    print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()
