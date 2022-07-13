-- https://leetcode.com/problems/employees-earning-more-than-their-managers/
select
    e.name as employee
from Employee e join Employee e1 on e.managerid = e1.id
where e.salary > e1.salary;
