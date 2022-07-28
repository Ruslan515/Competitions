-- https://leetcode.com/problems/employees-with-missing-information/
# Write your MySQL query statement below
with t1 as
(
    select
    employee_id
    from Employees
    where employee_id not in (
        select 
        employee_id
        from Salaries
    )
    union all
    select
    employee_id
    from Salaries
    where employee_id not in (
        select 
        employee_id
        from Employees
    )

)

select 
*
from t1
order by employee_id;
