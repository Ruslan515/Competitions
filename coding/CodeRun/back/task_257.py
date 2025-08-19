import sys

def compressed_substring(s, l, r):
    res = 0
    result = []
    count = 0
    for i in range(len(s)):
        if s[i].isalpha():
            count += 1
            if i >= l:
                result.append(res)
            if i == r:
                return res
        else:
            num = int(s[i])
            res += num * count
            if i >= l:
                result.append(res)
            if i == r:
                return res
            count = 0
    return sum(result[l:r+1])

def main():
	"""
	Для чтения входных данных необходимо получить их
	из стандартного потока ввода (sys.stdin).
	Данные во входном потоке соответствуют описанному
	в условии формату. Обычно входные данные состоят
	из нескольких строк.
	Можно использовать несколько методов:
	* input() -- читает одну строку из потока без символа
	перевода строки;
	* sys.stdin.readline() -- читает одну строку из потока,
	сохраняя символ перевода строки в конце;
	* sys.stdin.readlines() -- вернет список (list) строк,
	сохраняя символ перевода строки в конце каждой из них.
	Чтобы прочитать из строки стандартного потока:
	* число -- int(input()) # в строке должно быть одно число
	* строку -- input()
	* массив чисел -- map(int, input().split())
	* последовательность слов -- input().split()
	Чтобы вывести результат в стандартный поток вывода (sys.stdout),
	можно использовать функцию print() или sys.stdout.write().
	Возможное решение задачи "Вычислите сумму чисел в строке":
	print(sum(map(int, input().split())))
	"""
	s = input()
	q = int(input())
	answer = []
	for i in range(q):
		l, r = map(int, input().split())
		answer.append(compressed_substring(s, l, r))

	for num in answer:
		print(num)


if __name__ == '__main__':
	main()