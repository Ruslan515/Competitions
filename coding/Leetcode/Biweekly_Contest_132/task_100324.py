class Solution:
    def clearDigits(self, s: str) -> str:
        answer = ""
        st1 = []
        for ch in s[::-1]:
            st1.append(ch)

        st2 = []
        for ch in st1[::-1]:
            top = st1.pop()
            if ord('a') <= ord(top) <= ord('z'):
                st2.append(ch)
            else:
                st2.pop()

        answer = "".join(st2)
        return answer


def main():
    solve = Solution()

    s = "abc"
    answer = "abc"
    assert answer == solve.clearDigits(s)

    s = "cb34"
    answer = ""
    assert answer == solve.clearDigits(s)


if __name__ == "__main__":
    main()
