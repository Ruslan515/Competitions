# https://leetcode.com/contest/biweekly-contest-152/problems/design-spreadsheet/description/?slug=longest-special-path-ii&region=global_v2
class Spreadsheet:

    def __init__(self, rows: int):
        self.tbl = {
            f"{chr(code)}{i}": 0
            for code in range(ord("A"), ord("Z") + 1)
            for i in range(rows + 1)
        }

    def setCell(self, cell: str, value: int) -> None:
        self.tbl[cell] = value

    def resetCell(self, cell: str) -> None:
        self.tbl[cell] = 0

    def getVal(self, val: str) -> int:
        if self.tbl.get(val) is not None:
            val = int(self.tbl[val])
        else:
            val = int(val)
        return val

    def getValue(self, formula: str) -> int:
        first, second = list(map(self.getVal, formula[1:].split("+")))
        answer = first + second
        return answer


def main():
    spreadsheet = Spreadsheet(36)  # // Initializes a spreadsheet with 3 rows and 26 columns
    assert (72260 + 45645) == spreadsheet.getValue("=72260+45645")  # // returns 12 (5+7)
    assert 29561 == spreadsheet.getValue("=K36+29561")  # // returns 16 (10+6)
    spreadsheet.resetCell("U13")  # // resets A1 to 0


# def main():
#     spreadsheet = Spreadsheet(3)  # // Initializes a spreadsheet with 3 rows and 26 columns
#     assert 12 == spreadsheet.getValue("=5+7")  # // returns 12 (5+7)
#     spreadsheet.setCell("A1", 10)  # // sets A1 to 10
#     assert 16 == spreadsheet.getValue("=A1+6")  # // returns 16 (10+6)
#     spreadsheet.setCell("B2", 15)  # // sets B2 to 15
#     assert 25 == spreadsheet.getValue("=A1+B2")  # // returns 25 (10+15)
#     spreadsheet.resetCell("A1")  # // resets A1 to 0
#     assert 15 == spreadsheet.getValue("=A1+B2")  # // returns 15 (0+15)©leetcode


if __name__ == "__main__":
    main()
