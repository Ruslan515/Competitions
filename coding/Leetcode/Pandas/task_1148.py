# https://leetcode.com/problems/article-views-i/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    views.drop_duplicates(inplace=True)
    mask = views.author_id == views.viewer_id
    answer = views.loc[mask, ["author_id"]]
    answer.drop_duplicates(inplace=True)
    answer.sort_values(by=["author_id"], inplace=True)
    return answer.rename(columns={"author_id": "id"})


if __name__ == "__main__":
    Views = pd.DataFrame([], columns=['article_id', 'author_id', 'viewer_id', 'view_date']).astype(
        {'article_id': 'Int64', 'author_id': 'Int64', 'viewer_id': 'Int64', 'view_date': 'datetime64[ns]'})
