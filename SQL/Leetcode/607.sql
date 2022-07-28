-- https://leetcode.com/problems/sales-person/solution/
# Write your MySQL query statement below
with red_emp as
(
    select
    sales_id
    from orders
    where com_id = (
        select
        com_id
        from Company
        where name = 'RED'
    )    
)

select
name
from SalesPerson
where sales_id not in (
    select
    *
    from red_emp
)
