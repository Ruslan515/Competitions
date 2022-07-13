-- https://leetcode.com/problems/customers-who-never-order/
select 
name as Customers
from customers
where id not in (
    select 
    customerId 
    from Orders     
);

