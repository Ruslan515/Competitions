-- https://leetcode.com/problems/warehouse-manager/
# Write your MySQL query statement below
with t1 as
    (
        select
            product_id,
            Products.Width * Products.Length * Products.Height as product_volume
        from products
    )
select
    w.name as warehouse_name,
    sum(w.units * product_volume) as volume
from warehouse w join t1  on t1.product_id = w.product_id
group by w.name
order by volume;
