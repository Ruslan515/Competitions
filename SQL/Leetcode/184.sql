-- https://leetcode.com/problems/department-highest-salary/
# Write your MySQL query statement below

with t1 as (
    select 
    e.departmentId,
    max(e.salary) max_salary
    from Employee e
    group by e.departmentId
)

select
d.name as Department,
e.name as Employee,
e.salary as Salary
from Employee e join t1 on (e.departmentId = t1.departmentId and e.salary = t1.max_salary)
join Department d on e.departmentId = d.id;
