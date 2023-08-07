# https://leetcode.com/problems/department-highest-salary/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    temp = employee[["departmentId", "salary"]].groupby(by=["departmentId"]).agg(max)
    temp = employee.merge(temp, on=["departmentId", "salary"])
    temp = temp.merge(department, left_on="departmentId", right_on="id")
    temp.rename(columns={"name_x": "Employee", "name_y": "Department", "salary": "Salary"}, inplace=True)
    temp = temp[["Department", "Employee", "Salary"]]
    return temp

if __name__ == "__main__":
    Employee = pd.DataFrame([], columns=['id', 'name', 'salary', 'departmentId']).astype(
        {'id': 'Int64', 'name': 'object', 'salary': 'Int64', 'departmentId': 'Int64'})
    Department = pd.DataFrame([], columns=['id', 'name']).astype({'id': 'Int64', 'name': 'object'})

    assert answer.equals(find_customers(customers, orders))
