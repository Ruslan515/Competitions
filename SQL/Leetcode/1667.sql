-- https://leetcode.com/problems/fix-names-in-a-table/
# Write your MySQL query statement below
select
user_id, 
concat(ucase(left(name, 1)),lcase(substring(name, 2))) as name
from Users
order by user_id
