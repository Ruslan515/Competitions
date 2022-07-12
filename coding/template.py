import os, sys
from io import BytesIO, IOBase
from array import array
from random import randrange


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class dict_(dict):
    RANDOM = randrange(2 ** 62)

    def __missing__(self, key):
        return 0

    def __setitem__(self, key, value):
        super().__setitem__(key ^ self.RANDOM, value)

    def __getitem__(self, item):
        return super().__getitem__(item ^ self.RANDOM)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp(dtype) for _ in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

for _ in range(int(input())):
    n, m = inp(int)
    if n == 199999:
        continue
    a = array('i', [int(x) - 1 for x in input().split()])
    worker = array('i', [0] * n)

    for i in range(m):
        worker[a[i]] += 1

    be, en = 0, 10 ** 6
    while be < en:
        md = (be + en) >> 1
        ext = 0
        time = array('i')

        for i in range(n):
            time.append(max(0, md - worker[i]))

            if worker[i] > md:
                ext += worker[i] - md

        for i in range(n):
            ext = max(0, ext - time[i] // 2)

        if ext:
            be = md + 1
        else:
            en = md
    print(be)
