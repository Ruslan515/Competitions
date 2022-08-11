-- https://leetcode.com/problems/monthly-transactions-i/
with t1 as (
    select
        id,
        country,
        state,
        amount,
        date_format(trans_date, '%Y-%m') as month
    from Transactions
)
select
    month,
    country,
    count(*) as trans_count,
    sum(if(state='approved', 1, 0)) as approved_count,
    sum(t1.amount) as trans_total_amount,
    sum(if(state='approved', amount, 0)) as approved_total_amount
from t1
group by month, country
