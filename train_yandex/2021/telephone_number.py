# https://contest.yandex.ru/contest/27393/problems/C/

def clear_number(input_str):
    return (
        input_str
        .replace(")", "")
        .replace("(", "")
        .replace("+", "")
        .replace("-", "")
    )

def main():
    target_number = clear_number(input())
    if len(target_number) == 7:
        code = "495"
    else:
        code = target_number[1: 4]
    number = target_number[-7:]
    answer = []
    for i in range(3):
        current_number = clear_number(input())
        if len(current_number) == 7:
            code_current = "495"
        else:
            code_current = current_number[1: 4]
        current_number = current_number[-7:]
        if code == code_current and number == current_number:
            answer.append("YES")
        else:
            answer.append("NO")
    print("\n".join(answer))

if __name__ == "__main__":
    main()