# https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    df = teacher.groupby(["teacher_id"])["subject_id"].nunique().reset_index()
    df = df.rename({'subject_id': "cnt"}, axis=1)
    return df