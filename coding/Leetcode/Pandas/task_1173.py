# https://leetcode.com/problems/immediate-food-delivery-i/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    mask = delivery["order_date"] == delivery["customer_pref_delivery_date"]
    x = delivery.loc[mask].shape[0]
    y = delivery.shape[0]
    ans = round(x / y * 100, 2)
    return pd.DataFrame(data={"immediate_percentage": [ans]})
