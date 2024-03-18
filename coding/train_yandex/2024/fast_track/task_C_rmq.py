import math
import sys


def buildSparseTable(arr, n, lookup):
    # Initialize M for the intervals
    # with length 1
    for i in range(n):
        lookup[i][0] = arr[i]

    # Compute values from smaller
    # to bigger intervals
    i, j = 0, 1
    while (1 << j) <= n:

        # Compute maximum value for
        # all intervals with size 2^j
        while (i + (1 << j) - 1) < n:

            # For arr[2][10], we compare arr[lookup[0][7]]
            # and arr[lookup[3][10]]
            if (lookup[i][j - 1] >
                    lookup[i + (1 << (j - 1))][j - 1]):
                lookup[i][j] = lookup[i][j - 1]
            else:
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1]
            i += 1
        j += 1


def buildSparseTable_min(arr, n, lookup):
    # Initialize M for the intervals
    # with length 1
    for i in range(0, n):
        lookup[i][0] = arr[i]

    j = 1

    # Compute values from smaller to
    # bigger intervals
    while (1 << j) <= n:
        # Compute minimum value for all
        # intervals with size 2^j
        i = 0
        while (i + (1 << j) - 1) < n:
            # For arr[2][10], we compare arr[lookup[0][7]]
            # and arr[lookup[3][10]]
            if (lookup[i][j - 1] <
                    lookup[i + (1 << (j - 1))][j - 1]):
                lookup[i][j] = lookup[i][j - 1]
            else:
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1]

            i += 1
        j += 1


# Returns maximum of arr[L..R]
def query(L, R, lookup):
    # Find highest power of 2 that is smaller
    # than or equal to count of elements in given
    # range
    # For [2, 10], j = 3
    j = int(math.log(R - L + 1))

    # Compute maximum of last 2^j elements with first
    # 2^j elements in range
    # For [2, 10], we compare arr[lookup[0][3]] and
    # arr[lookup[3][3]]
    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j]):
        return lookup[L][j]

    else:
        return lookup[R - (1 << j) + 1][j]


# Returns minimum of arr[L..R]
def query_min(L, R, lookup):
    # Find highest power of 2 that is smaller
    # than or equal to count of elements in
    # given range. For [2, 10], j = 3
    j = int(math.log2(R - L + 1))

    # Compute minimum of last 2^j elements
    # with first 2^j elements in range.
    # For [2, 10], we compare arr[lookup[0][3]]
    # and arr[lookup[3][3]],
    if lookup[L][j] <= lookup[R - (1 << j) + 1][j]:
        return lookup[L][j]

    else:
        return lookup[R - (1 << j) + 1][j]


def main():
    n = int(sys.stdin.readline())
    temps = list(map(int, sys.stdin.readline().split()))
    size = 2 * n + 1
    MAX = size * int(math.log(size))
    lookup_min = [
        [0 for i in range(MAX)]
        for j in range(MAX)
    ]
    lookup_max = [
        [0 for i in range(MAX)]
        for j in range(MAX)
    ]

    buildSparseTable(temps, MAX, lookup_max)
    buildSparseTable_min(temps, MAX, lookup_min)

    b = int(sys.stdin.readline())
    ans = []
    for _ in range(b):
        t_min, t_max, d_min, d_max = list(map(int, sys.stdin.readline().split()))
        left = n + d_min
        right = n + d_max
        min_temp = query_min(left, right , lookup_min)
        max_temp = query(left, right , lookup_max)
        low = t_min > max_temp
        high = min_temp > t_max
        if low or high:
            ans.append("no")
            # sys.stdout.write("no\n")
        else:
            ans.append("yes")
            # sys.stdout.write("yes\n")

    sys.stdout.write("\n".join(ans))


if __name__ == '__main__':
    main()
