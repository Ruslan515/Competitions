class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
        count_people = 1
        for i in range(1, n):
            new_count = 2 * count_people


def read_data():
    n = int(input())
    delay = int(input())
    forget = int(input())
    return n, delay, forget

def main():
    n, delay, forget = read_data()
    s = Solution()
    print(s.peopleAwareOfSecret(n, delay, forget))

if __name__ == "__main__":
    main()