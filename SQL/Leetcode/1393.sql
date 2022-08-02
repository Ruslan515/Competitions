-- https://leetcode.com/problems/capital-gainloss/
# Write your MySQL query statement below
with t_buy as 
(
    select
        stock_name, 
        operation,
        sum(price) as sum_buy
    from Stocks
    where operation = 'Buy'
    group by stock_name, operation
),
t_sell as 
(
    select
        stock_name, 
        operation,
        sum(price) as sum_sell
    from Stocks
    where operation = 'Sell'
    group by stock_name, operation
)
select
    t_buy.stock_name,
    t_sell.sum_sell - t_buy.sum_buy as capital_gain_loss
from t_buy join t_sell on t_buy.stock_name = t_sell.stock_name
