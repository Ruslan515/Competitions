-- https://leetcode.com/problems/orders-with-maximum-quantity-above-average/
with t1 as (
    select
        order_id,
        avg(quantity) as avg_quantity,
        max(quantity) as max_quantity
    from OrdersDetails
    group by order_id
    order by order_id
),
    t2 as (
    select
        order_id
    from t1
    where max_quantity > (
        select
            max(avg_quantity)
        from t1
        )
    )

select
    *
from t2
