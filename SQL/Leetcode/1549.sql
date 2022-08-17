-- https://leetcode.com/problems/the-most-recent-orders-for-each-product/
with t1 as (
    select
        product_id,
        max(order_date) as last_date
    from Orders
    group by product_id
),
    t2 as (
        select
            o.order_id,
            o.order_date,
            o.product_id
        from Orders o join t1 on o.product_id = t1.product_id and o.order_date = t1.last_date
    ),
    t3 as (
        select
            p.product_name,
            p.product_id,
            t2.order_id,
            t2.order_date
        from t2 join Products p on t2.product_id = p.product_id
        order by p.product_name, p.product_id, t2.order_id
    )

select
    *
from t3
