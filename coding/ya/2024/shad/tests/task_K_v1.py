def main():
    n = int(input())  # Количество прямых у Алисы
    alice_lines = set()  # Множество для хранения нормализованных векторов нормалей
    for _ in range(n):
        a, b, _ = map(int, input().split())
        if b != 0:
            alice_lines.add(- a / b)
        else:
            alice_lines.add(float("inf"))

    q = int(input())  # Количество любимых прямых у Боба
    for _ in range(q):
        a, b, _ = map(int, input().split())
        if b != 0:
            t = - a / b
        else:
            t = float("inf")

        print("YES" if t in alice_lines else "NO")


if __name__ == "__main__":
    main()
