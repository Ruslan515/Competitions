import pandas as pd


def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    df_agg = orders.groupby(by=["customer_number"], as_index=False).count()
    return df_agg.loc[df_agg["order_number"].max() == df_agg["order_number"], ["customer_number"]]


if __name__ == "__main__":
    courses = pd.DataFrame(
        {
            "student": ["A", "B", "C", "D", "E", "F", "G", "H", "I", ],
            "class": ["Math", "English", "Math", "Biology", "Math", "Computer", "Math", "Math", "Math"],
        }
    )
    answer = pd.DataFrame(
        data={
            "class": ["Math"]
        }
    )
    assert answer.equals(find_classes(courses))
