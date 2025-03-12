import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    pivot_df = weather.pivot(index='month', columns='city', values='temperature')
    pivot_df.to_string(index=False)
    return pivot_df
