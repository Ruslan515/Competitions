# https://leetcode.com/problems/count-salary-categories/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    mask_low = accounts["income"] < 20000
    low = mask_low.sum()
    mask_avg = (
        (accounts["income"] >= 20000) &
        (accounts["income"] <= 50000)
    )
    avg = mask_avg.sum()
    mask_high = accounts["income"] > 50000
    high = mask_high.sum()
    ans = pd.DataFrame(
        data={
            "category": ["Low Salary", "Average Salary", "High Salary"],
            "accounts_count": [low, avg, high]
        }
    )
    return ans

