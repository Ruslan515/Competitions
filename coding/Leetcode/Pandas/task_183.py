# https://leetcode.com/problems/customers-who-never-order/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    answer = (
        pd.merge(
            customers, orders[["customerId"]],
            how="left",
            left_on="id",
            right_on="customerId",
            indicator=True
        )
        .query("_merge == 'left_only'")
        .drop(columns=["_merge", "id", "customerId"])
        .rename(columns={"name": "Customers"})
    )

    return answer


if __name__ == "__main__":
    customers = pd.DataFrame(
        data={
            "id": [1, 2, 3, 4],
            "name": ["Joe", "Henry", "Sam", "Max"],
        }
    )
    orders = pd.DataFrame(
        data={
            "id": [1, 2],
            "customerId": [3, 1]
        }
    )

    answer = pd.DataFrame(
        data={
            "Customers": ["Henry", "Max"]
        }
    )

    assert answer.equals(find_customers(customers, orders))
