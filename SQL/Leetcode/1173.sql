-- https://leetcode.com/problems/immediate-food-delivery-i/
with t1 as (
    select
        count(*)
    from Delivery
    where order_date = customer_pref_delivery_date
)
select
    round(100 * (select * from t1) / (
            select
                count(*)
            from Delivery
        ), 2) as immediate_percentage;
