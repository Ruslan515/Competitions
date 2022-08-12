-- https://leetcode.com/problems/find-the-team-size/
# Write your MySQL query statement below
with t1 as (
    select
        team_id,
        count(*) as team_size
    from Employee
    group by team_id
)

select
    e.employee_id,
    t1.team_size
from Employee e join t1 on e.team_id = t1.team_id
