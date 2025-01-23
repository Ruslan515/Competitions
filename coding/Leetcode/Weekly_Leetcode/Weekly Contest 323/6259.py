# https://leetcode.com/contest/weekly-contest-323/problems/design-memory-allocator/
from typing import List


class Allocator:

    def __init__(self, n: int):
        self.size = n
        self.memory = [-1] * n
        return

    def allocate(self, size: int, mID: int) -> int:
        ans = -1
        for i in range(self.size):
            if self.memory[i] == -1:
                if i + size <= self.size:
                    if sum(self.memory[i: i + size]) == (-1) * size:
                        for j in range(i, i + size):
                            self.memory[j] = mID
                        ans = i
                        break
                    else:
                        i += size
        return ans

    def free(self, mID: int) -> int:
        ans = 0
        while mID in self.memory:
            idx = self.memory.index(mID)
            self.memory[idx] = -1
            ans += 1
        return ans

def main():
    list_ans_exp = [None,0,1,2,1,3,1,6,3,-1,0]
    list_ans_out = [None]
    obj = Allocator(5)

    param = obj.free(4)
    list_ans_out.append(param)

    param = obj.allocate(9,5)
    list_ans_out.append(param)

    param = obj.allocate(5,8)
    list_ans_out.append(param)

    param = obj.allocate(4,8)
    list_ans_out.append(param)

    param = obj.allocate(3,2)
    list_ans_out.append(param)

    param = obj.free(6)
    list_ans_out.append(param)

    param = obj.allocate(9,9)
    list_ans_out.append(param)

    param = obj.free(6)
    list_ans_out.append(param)

    print(list_ans_out)





if __name__ == "__main__":
    main()