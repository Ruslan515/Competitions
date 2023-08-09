# https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    df_agg = actor_director.groupby(by=["actor_id", "director_id"], as_index=False).agg("nunique")
    return df_agg.loc[df_agg["timestamp"] >= 3, ["actor_id", "director_id"]]


if __name__ == "__main__":
    data = [[1, 1, 0], [1, 1, 1], [1, 1, 2], [1, 2, 3], [1, 2, 4], [2, 1, 5], [2, 1, 6]]
    ActorDirector = pd.DataFrame(data, columns=['actor_id', 'director_id', 'timestamp']).astype(
        {'actor_id': 'int64', 'director_id': 'int64', 'timestamp': 'int64'})
    answer = pd.DataFrame(
        data={
            "actor_id": [1],
            "director_id": [1]
        }
    )
    assert answer.equals(actors_and_directors(ActorDirector))
