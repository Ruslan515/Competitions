-- https://leetcode.com/problems/count-student-number-in-departments/
# Write your MySQL query statement below
with t1 as (
    select
        dept_id,
        count(*) as student_number
    from Student
    group by dept_id
)

select
    d.dept_name,
    coalesce(t1.student_number, 0) as student_number
from Department d left join t1 on d.dept_id = t1.dept_id
order by student_number desc, dept_name
