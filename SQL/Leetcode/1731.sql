-- https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/
# Write your MySQL query statement below
with t1 as (
    select
        reports_to,
        count(*) as reports_count,
        round(avg(age), 0) as average_age
    from Employees
    where reports_to is not null
    group by reports_to
)

select
    e.employee_id,
    e.name,
    t1.reports_count,
    t1.average_age
from Employees e join t1 on e.employee_id = t1.reports_to
order by e.employee_id
