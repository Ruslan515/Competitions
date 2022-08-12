-- https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
# Write your MySQL query statement below
with t2 as (
        select
            managerId
        from Employee
        where managerId is not NULL
        group by managerId
        having count(*) >= 5
    )

select
    e.name
from t2 join Employee e on t2.managerId = e.id;
