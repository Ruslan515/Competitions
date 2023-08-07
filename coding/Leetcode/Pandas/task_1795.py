# https://leetcode.com/problems/rearrange-products-table/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    t1 = products[["product_id", "store1"]].rename(columns={"store1": "price"}).dropna()
    t1["store"] = "store1"
    t2 = products[["product_id", "store2"]].rename(columns={"store2": "price"}).dropna()
    t2["store"] = "store2"
    t3 = products[["product_id", "store3"]].rename(columns={"store3": "price"}).dropna()
    t3["store"] = "store3"
    answer = pd.concat([t1, t2, t3])
    return answer[["product_id", "store", "price"]]
