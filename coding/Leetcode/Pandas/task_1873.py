# https://leetcode.com/problems/calculate-special-bonus/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    mask_not_bonus = (
            (employees["employee_id"] % 2 == 0)
            |
            (employees["name"].str.startswith("M"))
    )
    employees["bonus"] = 0
    employees.loc[~mask_not_bonus, "bonus"] = employees.loc[~mask_not_bonus, "salary"]
    employees.sort_values(by=["employee_id"], inplace=True)
    return employees[["employee_id", "bonus"]]
