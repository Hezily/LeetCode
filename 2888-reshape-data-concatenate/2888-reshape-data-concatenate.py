import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:

    df_combine = pd.concat([df1, df2])
    return df_combine