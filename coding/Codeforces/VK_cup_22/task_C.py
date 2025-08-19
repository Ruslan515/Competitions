from collections import Counter

def read_data():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def main():
    t = int(input())
    for _ in range(t):
        n, a = read_data()
        a_dict = Counter(a)
        list_tuple = []
        for k, v in a_dict.items():
            if v == 1:
                tpl = (k, -1)
            else:
                tpl = (k, k + 1)
            list_tuple.append(tpl)
        print(list_tuple)
        tpl = list_tuple[0]
        s_one, f_one = tpl[0], tpl[1]
        t = [s_one]
        if f_one != -1:
            t.append(f_one)

        new_list = []
        for i in range(len(list_tuple)):
            tpl = list_tuple[i]
            s, f = tpl[0], tpl[1]
            if (s - f_one) == 0:
                t.append(f)
                f_one = f
            elif (s - f_one) > 1:
                new_list.append(t)
                t = [s]
                s_one = s
                if f != -1:
                    t.append(f)
                    f_one = f
                else:
                    f_one = s
            else:
                t.append(s)
                t.append(f)
                s_one = s
                f_one = f

        print(len(new_list))


if __name__ == "__main__":
    main()