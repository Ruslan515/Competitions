# https://leetcode.com/problems/students-and-examinations/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd


def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame,
                              examinations: pd.DataFrame) -> pd.DataFrame:
    # if students.shape[0] == 0 or subjects.shape[0] == 0 or examinations.shape[0] == 0:
    #     return pd.DataFrame(data={"student_id": [], "student_name": [], "subject_name": [], })
    df_agg = examinations.groupby(by=["student_id", "subject_name"], as_index=False).size()
    df_cross = students.merge(subjects, how="cross")
    df_cross = df_cross.merge(df_agg, on=["student_id", "subject_name"], how="left")
    df_cross.fillna(0, inplace=True)
    df_cross.rename(columns={"size": "attended_exams"}, inplace=True)
    df_cross.sort_values(by=["student_id", "subject_name"], inplace=True)
    return df_cross[["student_id", "student_name", "subject_name", "attended_exams"]]


if __name__ == "__main__":
    data = [[1, 'Alice'], [2, 'Bob'], [13, 'John'], [6, 'Alex']]
    Students = pd.DataFrame(data, columns=['student_id', 'student_name']).astype(
        {'student_id': 'Int64', 'student_name': 'object'})
    data = [['Math'], ['Physics'], ['Programming']]
    Subjects = pd.DataFrame(data, columns=['subject_name']).astype({'subject_name': 'object'})
    data = [[1, 'Math'], [1, 'Physics'], [1, 'Programming'], [2, 'Programming'], [1, 'Physics'], [1, 'Math'],
            [13, 'Math'], [13, 'Programming'], [13, 'Physics'], [2, 'Math'], [1, 'Math']]
    Examinations = pd.DataFrame(data, columns=['student_id', 'subject_name']).astype(
        {'student_id': 'Int64', 'subject_name': 'object'})
    answer = pd.DataFrame(
        data={
            "actor_id": [1],
            "director_id": [1]
        }
    )
    students_and_examinations(Students, Subjects, Examinations)
