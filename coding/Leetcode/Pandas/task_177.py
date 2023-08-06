# https://leetcode.com/problems/nth-highest-salary/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    employee.drop_duplicates(subset=["salary"], inplace=True)
    x = employee.shape[0]
    if N > x:
        return pd.DataFrame(data={f"getNthHighestSalary({N})": [None]})
    employee.sort_values(by=["salary"], inplace=True, ascending=False)
    return pd.DataFrame(data={f"getNthHighestSalary({N})": [employee["salary"].iloc[N - 1]]})


if __name__ == "__main__":
    employee = pd.DataFrame(
        {
            "id": [1, 2, 3, ],
            "salary": [100, 200, 300],
        }
    )
    n = 1
    answer = pd.DataFrame(
        data={
            "getNthHighestSalary(1)": [300]
        }
    )
    assert answer.equals(nth_highest_salary(employee, n))

    employee = pd.DataFrame(
        {
            "id": [1, 2, ],
            "salary": [100, 100],
        }
    )
    n = 2
    answer = pd.DataFrame(
        data={
            "getNthHighestSalary(2)": [None]
        }
    )
    assert answer.equals(nth_highest_salary(employee, n))

    employee = pd.DataFrame(
        {
            "id": [1, 2, 3, ],
            "salary": [100, 200, 300],
        }
    )
    n = 2
    answer = pd.DataFrame(
        data={
            "getNthHighestSalary(2)": [200]
        }
    )
    assert answer.equals(nth_highest_salary(employee, n))
