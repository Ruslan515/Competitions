# https://leetcode.com/problems/print-in-order/?envType=problem-list-v2&envId=concurrency
from time import sleep


class Foo:
    def __init__(self):
        Foo.cnt = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        while True:
            if Foo.cnt == 0:
                printFirst()
                Foo.cnt += 1
                break
            else:
                sleep(60)
    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        while True:
            if Foo.cnt == 1:
                printSecond()
                Foo.cnt += 1
                break
            else:
                sleep(3)

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        while True:
            if Foo.cnt == 2:
                printThird()
                Foo.cnt += 1
                break
            else:
                sleep(60)