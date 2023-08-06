# https://leetcode.com/problems/fix-names-in-a-table/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users["name"] = users["name"].str.title()
    users.sort_values(by=["user_id"], inplace=True)
    return users

