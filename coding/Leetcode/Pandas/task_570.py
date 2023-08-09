# https://leetcode.com/problems/managers-with-at-least-5-direct-reports/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df_agg = employee.groupby(by=["managerId"], ).size().reset_index().rename(columns={0: "count"})
    df_agg = df_agg.loc[df_agg["count"] >= 5, ["managerId"]]
    employee = employee.merge(df_agg, left_on="id", right_on="managerId")
    return employee[["name"]]


if __name__ == "__main__":
    data = [[101, 'John', 'A', None], [102, 'Dan', 'A', 101], [103, 'James', 'A', 101], [104, 'Amy', 'A', 101],
            [105, 'Anne', 'A', 101], [106, 'Ron', 'B', 101]]
    Employee = pd.DataFrame(data, columns=['id', 'name', 'department', 'managerId']).astype(
        {'id': 'Int64', 'name': 'object', 'department': 'object', 'managerId': 'Int64'})

    answer = pd.DataFrame(
        data={
            "name": ["John"],
        }
    )
    assert answer.equals(find_managers(Employee))
