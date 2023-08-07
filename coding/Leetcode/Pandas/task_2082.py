# https://leetcode.com/problems/the-number-of-rich-customers/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

N = 500
def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    mask = store["amount"] > N
    ans = store.loc[mask, ["customer_id"]].nunique()
    return pd.DataFrame(data={"rich_count": ans})
