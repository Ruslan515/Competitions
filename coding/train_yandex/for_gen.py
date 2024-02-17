def print_p(file_path, p_num):
    i = 0
    with open(file_path, 'r') as f:
        while True:
            line = f.readline().strip()
            if line is None:
                break
            if set(line) == set("@"):
                i += 1
                if i == p_num:
                    break
        while True:
            line = f.readline().strip()
            if line is None:
                break
            if set(line) == set("@"):
                return
            print(line)


def main():
    print_p("data.txt", 2)


if __name__ == '__main__':
    main()
