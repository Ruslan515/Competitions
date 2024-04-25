# # https://contest.yandex.ru/contest/59541/problems/A
# """
# 3
# -1000000000 0 1000000000
# 12
# -999999999 999999999 1 1
# -1000000000 -1000000000 1 1
# 1000000000 1000000000 1 1
# -1000000000 1000000000 3 3
# -999999999 1000000000 2 2
# -1000000000 999999999 2 2
# 0 999999999 1 1
# -1 999999999 1 1
# 1 999999999 0 0
# -999999999 -1 0 -1
# -999999999 0 1 1
# -999999999 1 1 1
# """
#
# import sys
#
#
# def binary_search(in_arr, key, direction: bool = False):
#     low = 0
#     high = len(in_arr) - 1
#     n = len(in_arr)
#     while low <= high:
#         mid = (low + high) // 2
#         midVal = in_arr[mid]
#         if midVal == key:
#             if direction:  # вправо
#                 while mid < n - 1 and in_arr[mid] == in_arr[mid + 1]:
#                     mid += 1
#             else:
#                 while mid > 0 and in_arr[mid] == in_arr[mid - 1]:
#                     mid -= 1
#             return mid
#         if midVal > key:
#             high = mid - 1
#         else:
#             low = mid + 1
#     return mid
#
#
# def main():
#     n = int(sys.stdin.readline())
#     arr = list(map(int, sys.stdin.readline().split()))
#     k = int(sys.stdin.readline())
#     answer = []
#     arr.sort()
#     for _ in range(k):
#         l, r = map(int, sys.stdin.readline().split())
#         if l == r:
#             postition = binary_search(arr, l)
#             if arr[postition] == l:
#                 answer.append(1)
#             else:
#                 answer.append(0)
#         else:
#
#             left = binary_search(arr, l)
#             right = binary_search(arr, r, direction=True)
#             if right == left and arr[left] == l:
#                 diff = 0
#             else:
#                 if left > 0:
#                     left -= 1
#                 diff = right - left - 1
#             answer.append(diff)
#
#     answer = " ".join(map(str, answer))
#     sys.stdout.write(answer + "\n")
#

def main():
    def preprocess(arr):
        # Сортируем и уникализируем значения
        sorted_unique_values = sorted(set(arr))
        # Словарь для преобразования значения в индекс
        value_to_index = {value: index for index, value in enumerate(sorted_unique_values)}
        return value_to_index

    def prefix_sums(arr, value_to_index):
        # Создаем массив префиксных сумм
        prefix_sum = [0] * (len(value_to_index) + 1)
        for value in arr:
            index = value_to_index[value]
            prefix_sum[index + 1] += 1
        # Считаем префиксные суммы
        for i in range(1, len(prefix_sum)):
            prefix_sum[i] += prefix_sum[i - 1]
        return prefix_sum

    def count_in_range(prefix_sum, value_to_index, L, R):
        # Находим индексы для L и R
        L_index = value_to_index.get(L, 0)
        R_index = value_to_index.get(R, len(value_to_index) - 1)
        # Возвращаем разницу префиксных сумм
        return prefix_sum[R_index + 1] - prefix_sum[L_index]

    # Чтение ввода (пример)
    N = int(input())
    arr = list(map(int, input().split()))
    K = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(K)]

    # Предобработка
    value_to_index = preprocess(arr + [L for L, R in queries] + [R for L, R in queries])
    prefix_sum = prefix_sums(arr, value_to_index)

    # Обработка запросов
    for L, R in queries:
        print(count_in_range(prefix_sum, value_to_index, L, R), end=" ")


if __name__ == "__main__":
    main()
