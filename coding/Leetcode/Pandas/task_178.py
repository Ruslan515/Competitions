# https://leetcode.com/problems/second-highest-salary/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores["rank"] = scores["score"].rank(method="dense", ascending=False).astype(int)
    scores.sort_values(by=["score"], inplace=True, ascending=False)
    return scores[["score", "rank"]]

if __name__ == "__main__":
    scores = pd.DataFrame(
        data={
            "id": [1, 2, 3, 4, 5, 6],
            "score": [3.50, 3.65, 4.00, 3.85, 4.00, 3.65],
        }
    )

    print(order_scores(scores).head(scores.shape[0]))
