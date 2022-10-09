# def F_with_mem(i, list_fib):
#     if list_fib[i] != -1:
#         return list_fib[i]
#     elif i < 2:
#         return i
#     else:
#         list_fib[i] = F_with_mem(i - 1, list_fib) + F_with_mem(i - 2, list_fib)
#     return list_fib[i]
#
# def F_with_tab(i, list_fib):
#     list_fib[0], list_fib[1] = 0, 1
#     for j in range(2, i + 1):
#         list_fib[j] = list_fib[j - 1] + list_fib[j - 2]
#     return list_fib[i]
#
#
# def F_with_const_memory(i):
#     if i < 2:
#         return i
#     prev_prev = 0
#     prev = 1
#     answer = 0
#     for idx in range(2, i + 1):
#         answer = prev_prev + prev
#         prev_prev = prev
#         prev = answer
#
#     return answer

def grasshopper(n, k):
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        sum_all = 0
        for j in range(1, k + 1):
            sum_all += dp[i - j]
        dp[i] = sum_all
    return dp[n]

def turtle_with_back(n, m, apple):
    INF = float('inf')
    dp = [[INF] * (m + 1)] * (n + 1)
    dp[1][1] = apple[1][1]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i > 1 or j > 1:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + apple[i][j]

    i, j = n, m
    path = []
    while i != 1 or j != 1:
        path.append((i, j))
        if dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return dp[n][m], path.reverse()

def turtle_with_prev(n, m, apple):
    INF = float('inf')
    dp = [[INF] * (m + 1)] * (n + 1)
    prev = [[0] * (m + 1)] * (n + 1)
    dp[1][1] = apple[1][1]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i > 1 or j > 1:
                if dp[i - 1][j] > dp[i][j - 1]:
                    dp[i][j] = dp[i - 1][j]
                    prev[i][j] = (i - 1, j)
                else:
                    dp[i][j] = dp[i][j - 1]
                    prev[i][j] = (i, j - 1)
                dp[i][j] += apple[i][j]

    i, j = n, m
    path = []
    while i > 0 or j > 0:
        path.append((i, j))
        temp = i
        i = prev[i][j][0]
        j = prev[temp][j][1]

    return dp[n][m], path.reverse()



if __name__ == "__main__":
    # n = 100
    # list_fib = [-1] * (n + 1)
    # assert F_with_mem(n, list_fib) == 354224848179261915075
    # print(F_with_mem(n, list_fib))
    # assert F_with_tab(n, list_fib) == 354224848179261915075
    # print(F_with_tab(n, list_fib))
    # assert F_with_const_memory(n) == 354224848179261915075
    # print(F_with_const_memory(n))

    print(grasshopper(5, 2))