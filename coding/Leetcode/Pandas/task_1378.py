# https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    employees = employees.merge(employee_uni, how="left", on="id")
    return employees[["unique_id", "name"]]

if __name__ == "__main__":
    data = [[1, 'Alice'], [7, 'Bob'], [11, 'Meir'], [90, 'Winston'], [3, 'Jonathan']]
    Employees = pd.DataFrame(data, columns=['id', 'name']).astype({'id': 'int64', 'name': 'object'})
    data = [[3, 1], [11, 2], [90, 3]]
    EmployeeUNI = pd.DataFrame(data, columns=['id', 'unique_id']).astype({'id': 'int64', 'unique_id': 'int64'})
    answer = pd.DataFrame(
        data={
            "unique_id": [None, None, 2, 3, 1],
            "name": ["Alice", "Bob", "Meir", "Winston", "Jonathan"]
        }
    )
    assert answer.equals(replace_employee_id(Employees, EmployeeUNI))
