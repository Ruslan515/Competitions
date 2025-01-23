# https://leetcode.com/contest/weekly-contest-323/problems/design-memory-allocator/
class Allocator:
    def __init__(self, n: int):
        self.q = [0] * n
        self.allo_me = defaultdict(list)

    def allocate(self, size: int, m: int) -> int:
        idx, s = -1, 0
        for i in range(len(self.q)):
            if self.q[i] == 0:
                if idx == -1:
                    idx, s = i, 1
                else:
                    s += 1
                if s == size:
                    break
            else:
                idx, s = -1, 0
        if s == size:
            for i in range(idx, idx + size):
                self.q[i] = m
                self.allo_me[m].append(i)
        else:
            idx = -1
        return idx

    def free(self, m: int) -> int:
        if m not in self.allo_me:
            return 0
        ans = len(self.allo_me[m])
        for i in self.allo_me[m]:
            self.q[i] = 0
        self.allo_me[m] = []
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