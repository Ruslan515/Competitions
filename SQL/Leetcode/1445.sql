-- https://leetcode.com/problems/apples-oranges/
with t_app as (
    select
        sale_date,
        sold_num as sold_num_app
    from Sales
    where fruit = 'apples'
),
    t_oran as (
    select
        sale_date,
        sold_num as sold_num_oran
    from Sales
    where fruit = 'oranges'
    )
select
    t_app.sale_date,
    t_app.sold_num_app - t_oran.sold_num_oran as diff
from t_app join t_oran on t_app.sale_date = t_oran.sale_date
order by sale_date
