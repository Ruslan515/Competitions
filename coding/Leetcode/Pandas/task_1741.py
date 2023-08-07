# https://leetcode.com/problems/find-total-time-spent-by-each-employee/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees["total_time"] = employees["out_time"] - employees["in_time"]
    employees = employees[["event_day", "emp_id", "total_time"]].groupby(by=["event_day", "emp_id"], as_index=False).agg(sum)
    employees.rename(columns={"event_day": "day"}, inplace=True)
    return employees
