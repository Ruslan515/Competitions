# https://leetcode.com/problems/patients-with-a-condition/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    mask = (
        patients["conditions"].str.match(r"^[a-zA-Z0-9]* DIAB1")
    )
    patients = patients.loc[mask]
    return patients