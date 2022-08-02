-- https://leetcode.com/problems/find-total-time-spent-by-each-employee/submissions/
# Write your MySQL query statement below
with t1 
as (
    select
        emp_id, 
        event_day,
        out_time - in_time as all_time
    from Employees
)
select 
    event_day as day, 
    emp_id,
    sum(all_time) as total_time
from t1
group by event_day, emp_id
