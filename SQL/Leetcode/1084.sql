-- https://leetcode.com/problems/sales-analysis-iii/
# Write your MySQL query statement below
with t_first_quarter as 
(
    select 
        distinct product_id
    from Sales
    where '2019-01-01' <= sale_date <= '2019-03-31'
),
t_not_first_quarter as
(
    select 
        distinct product_id
    from Sales
    where sale_date < '2019-01-01' or sale_date > '2019-03-31'
),
t_exc as
(
    select 
        distinct product_id
    from t_first_quarter
    where product_id not in (
        select 
            distinct product_id
        from t_not_first_quarter
    )
)

select
    p.product_id,
    p.product_name
from t_exc t1 join Product p on t1.product_id = p.product_id
