# https://leetcode.com/problems/game-play-analysis-i/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    ans = activity[["player_id", "event_date"]].groupby(by=["player_id"], as_index=False).agg(min)
    ans.rename(columns={"event_date": "first_login"}, inplace=True)
    return ans
