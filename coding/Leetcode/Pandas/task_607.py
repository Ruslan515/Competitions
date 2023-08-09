# https://leetcode.com/problems/sales-person/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    id_x = company.loc[company["name"] == "RED", "com_id"]
    id = id_x.iloc[0]
    s_id = orders.loc[orders["com_id"] == id, ["sales_id"]]
    df_concat = pd.concat([sales_person[["sales_id"]], s_id]).drop_duplicates(keep=False)
    df_concat = df_concat.merge(sales_person[["sales_id", "name"]])
    return df_concat[["name"]]

if __name__ == "__main__":
    data = [[1, 'John', 100000, 6, '4/1/2006'], [2, 'Amy', 12000, 5, '5/1/2010'], [3, 'Mark', 65000, 12, '12/25/2008'],
            [4, 'Pam', 25000, 25, '1/1/2005'], [5, 'Alex', 5000, 10, '2/3/2007']]
    SalesPerson = pd.DataFrame(data, columns=['sales_id', 'name', 'salary', 'commission_rate', 'hire_date']).astype(
        {'sales_id': 'Int64', 'name': 'object', 'salary': 'Int64', 'commission_rate': 'Int64',
         'hire_date': 'datetime64[ns]'})
    data = [[1, 'RED', 'Boston'], [2, 'ORANGE', 'New York'], [3, 'YELLOW', 'Boston'], [4, 'GREEN', 'Austin']]
    Company = pd.DataFrame(data, columns=['com_id', 'name', 'city']).astype(
        {'com_id': 'Int64', 'name': 'object', 'city': 'object'})
    data = [[1, '1/1/2014', 3, 4, 10000], [2, '2/1/2014', 4, 5, 5000], [3, '3/1/2014', 1, 1, 50000],
            [4, '4/1/2014', 1, 4, 25000]]
    Orders = pd.DataFrame(data, columns=['order_id', 'order_date', 'com_id', 'sales_id', 'amount']).astype(
        {'order_id': 'Int64', 'order_date': 'datetime64[ns]', 'com_id': 'Int64', 'sales_id': 'Int64',
         'amount': 'Int64'})

    answer = pd.DataFrame(
        data={
            "name": ["Amy", "Mark", "Alex"],
        }
    )
    assert answer.equals(sales_person(SalesPerson, Company, Orders))
