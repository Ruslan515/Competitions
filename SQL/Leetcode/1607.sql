-- https://leetcode.com/problems/sellers-with-no-sales/
# Write your MySQL query statement below
with t1 as (
    select
        seller_id
    from Orders
    where year(sale_date) = '2020'
)
select
    seller_name
from  Seller
where seller_id not in (
    select
        *
    from t1
    )
order by seller_name
