import pandas as pd

date = pd.Timestamp("today").date() - pd.DateOffset(days=7)
print(date)