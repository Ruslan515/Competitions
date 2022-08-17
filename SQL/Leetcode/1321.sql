-- https://leetcode.com/problems/restaurant-growth/
with t1 as (
    select
        visited_on,
        sum(amount) as sum_amm
    from Customer
    group by visited_on
),
    t2 as (
    select
        *,
        sum(sum_amm) over (order by visited_on rows between 6 preceding and current row ) as sum_am,
        round(avg(sum_amm) over (order by visited_on rows between 6 preceding and current row ), 2) as avg_am,
        min(visited_on) over (order by visited_on) as min_date
    from t1
    ),
    t3 as (
        select
            visited_on,
            sum_am as amount,
            avg_am as average_amount
        from t2
        where visited_on >= min_date + 6
        order by visited_on
    )

select
    *
from t3
