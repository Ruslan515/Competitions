-- https://leetcode.com/problems/bank-account-summary-ii/
# Write your MySQL query statement below
with t1 
as (
    select
        account,
        sum(amount) as balance
    from Transactions
    group by account
    having sum(amount) > 10000
)
select
    u.name,
    t1.balance
from Users u join t1 on u.account = t1.account
