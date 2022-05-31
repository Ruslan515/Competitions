# https://leetcode.com/contest/weekly-contest-295/problems/rearrange-characters-to-make-target-string/

class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        from collections import defaultdict
        target_dict = defaultdict(int)
        for char in target:
            target_dict[char] += 1

        my_dict = {char: 0 for char in target}

        set_target = set(target)
        for char in s:
            if char in set_target:
                my_dict[char] += 1

        set_new = set(my_dict.keys())
        if set_new == set_target:
            for char in set_target:
                my_dict[char] = int(my_dict[char] / target_dict[char])
        else:
            return 0

        min_count = min(my_dict.values())
        return min_count

def read_data():
    s = input()
    target = input()
    return s, target

def main():
    s, target = read_data()
    solution = Solution()
    print(solution.rearrangeCharacters(s, target))

if __name__ == "__main__":
    main()