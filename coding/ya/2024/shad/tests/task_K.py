from math import gcd


def normalize(a, b):
    # Нормализация вектора путем деления на НОД
    divisor = gcd(a, b)
    return (a // divisor, b // divisor)


def main():
    n = int(input())  # Количество прямых у Алисы
    alice_lines = set()  # Множество для хранения нормализованных векторов нормалей
    for _ in range(n):
        a, b, _ = map(int, input().split())
        # alice_lines.add(normalize(a, b))
        alice_lines.add(a / b)

    q = int(input())  # Количество любимых прямых у Боба
    for _ in range(q):
        a, b, _ = map(int, input().split())
        # Проверяем наличие параллельной прямой в множестве
        # t = normalize(a, b)
        t = a / b

        print("YES" if t in alice_lines else "NO")


if __name__ == "__main__":
    main()
