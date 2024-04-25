import pandas as pd
import timeit
import time

N = 10000


def func_apply():
    df = pd.DataFrame(
        {
            "number": [1, 2, 3, 4, 5],
            "city": ["msk", "reg", "msk", "reg", "reg"]
        }
    )
    df["city"] = df["city"].apply(lambda x: 0 if x == "msk" else 1)


def func_map():
    df = pd.DataFrame(
        {
            "number": [1, 2, 3, 4, 5],
            "city": ["msk", "reg", "msk", "reg", "reg"]
        }
    )
    df["city"] = df["city"].map({"msk": 0, "reg": 1})


def func_sub():
    df = pd.DataFrame(
        {
            "number": [1, 2, 3, 4, 5],
            "city": ["msk", "reg", "msk", "reg", "reg"]
        }
    )

    def my_func(x):
        if x == "msk":
            return 0
        else:
            return 1

    df["city"] = list(map(my_func, df["city"]))


def main():
    for func in [func_apply, func_map, func_sub]:
        start = time.time()
        for i in range(N):
            func()
        end = time.time()
        print(end - start)


if __name__ == '__main__':
    main()
