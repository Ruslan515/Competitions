import pandas as pd


def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    df_agg = (
        daily_sales
        .groupby(by=["date_id", "make_name"],as_index=False)
        .agg(
            unique_leads=("lead_id", "nunique"),
            unique_partners=("partner_id", "nunique")
        )
    )
    return df_agg

    groups = activities.groupby('sell_date')

    stats = groups.agg(
        num_sold=('product', 'nunique'),
        products=('product', lambda x: ','.join(sorted(set(x))))
    ).reset_index()

    stats.sort_values('sell_date', inplace=True)

    return stats