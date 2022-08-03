-- https://leetcode.com/problems/market-analysis-i/
# Write your MySQL query statement below
with t1 as
(
    select
        buyer_id,
        count(buyer_id) as orders_in_2019
    from Orders
    where year(order_date) = 2019
    group by buyer_id
)
select
    u.user_id as buyer_id, 
    u.join_date,
    coalesce(t1.orders_in_2019, 0) as orders_in_2019
from Users u left join t1 on u.user_id = t1.buyer_id
