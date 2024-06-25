from typing import List


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        answer = False
        n = len(hand)
        if n % groupSize != 0:
            return answer
        mp = dict()
        for h in hand:
            mp[h] = mp.get(h, 0) + 1
        if len(mp) < groupSize:
            return answer

        for x in range(n // groupSize):
            prev = None
            list_remove = []
            keys = list(mp.keys())
            keys.sort()
            for i in range(groupSize):
                key = keys[i]
                if prev is None:
                    prev = key
                else:
                    if prev != key - 1:
                        return answer
                    else:
                        prev = key
                mp[key] -= 1
                if mp[key] == 0:
                    list_remove.append(key)
                    # mp.pop(key)
                    # keys.remove(key)
            for r in list_remove:
                mp.pop(r)
                keys.remove(r)
            if len(keys) < groupSize and len(mp) != 0:
                return answer

        answer = True
        return answer


def main():
    solve = Solution()

    hand = [0, 0]
    groupSize = 2
    answer = False
    assert answer == solve.isNStraightHand(hand, groupSize)

    hand = [1, 2, 2, 3, 3, 3, 4, 4, 5]
    groupSize = 3
    answer = True
    assert answer == solve.isNStraightHand(hand, groupSize)

    hand = [1, 1, 2, 2, 3, 3]
    groupSize = 2
    answer = False
    assert answer == solve.isNStraightHand(hand, groupSize)

    hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]
    groupSize = 3
    answer = True
    assert answer == solve.isNStraightHand(hand, groupSize)

    hand = [1, 2, 3, 4, 5]
    groupSize = 4
    answer = False
    assert answer == solve.isNStraightHand(hand, groupSize)


if __name__ == "__main__":
    main()
