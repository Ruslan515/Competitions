# https://leetcode.com/problems/tallest-billboard/description/


class Solution(object):
    def tallestBillboard(self, rods):
        # Helper function to collect every combination `(left, right)`
        def helper(half_rods):
            states = set()
            states.add((0, 0))
            for r in half_rods:
                new_states = set()
                for left, right in states:
                    new_states.add((left + r, right))
                    new_states.add((left, right + r))
                states |= new_states

            dp = {}
            for left, right in states:
                dp[left - right] = max(dp.get(left - right, 0), left)
            return dp

        n = len(rods)
        first_half = helper(rods[:n // 2])
        second_half = helper(rods[n // 2:])

        answer = 0
        for diff in first_half:
            if -diff in second_half:
                answer = max(answer, first_half[diff] + second_half[-diff])
        return answer


def main():
    solve = Solution()

    rods = [1, 2, 3, 6]
    answer = 6
    assert answer == solve.tallestBillboard(rods)

    rods = [1, 2, 3, 4, 5, 6]
    answer = 10
    assert answer == solve.tallestBillboard(rods)

    rods = [1, 2]
    answer = 0

    assert answer == solve.tallestBillboard(rods)

    return 0


if __name__ == "__main__":
    main()
