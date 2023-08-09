import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df_agg = courses.groupby(by=["class"], as_index=False).count()
    return df_agg.loc[df_agg["student"] >= 5, ["class"]]

if __name__ == "__main__":
    courses = pd.DataFrame(
        {
            "student": ["A", "B", "C", "D", "E", "F", "G", "H", "I",],
            "class": ["Math", "English", "Math", "Biology", "Math", "Computer", "Math", "Math", "Math"],
        }
    )
    answer = pd.DataFrame(
        data={
            "class": ["Math"]
        }
    )
    assert answer.equals(find_classes(courses))
