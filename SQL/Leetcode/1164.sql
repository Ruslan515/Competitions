-- https://leetcode.com/problems/product-price-at-a-given-date/
with t1 as (
    select
        distinct product_id,
                 10 as start_price
    from Products
),
    t2 as (
        select
            product_id,
            max(change_date) as max_date
        from Products
        where change_date <= '2019-08-16'
        group by product_id
    ),
    t3 as (
        select
            t2.product_id,
            p.new_price
        from t2 join Products p on t2.product_id = p.product_id and t2.max_date = p.change_date
    ),
    t4 as (
        select
            t1.product_id,
            case
                when t3.new_price is null then 10
                else t3.new_price
            end as price
        from t1 left join t3 on t1.product_id = t3.product_id
    )

select
    *
from t4
