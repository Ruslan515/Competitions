-- https://leetcode.com/problems/top-travellers/
# Write your MySQL query statement below
with t1 as
(
    select
        user_id,
        sum(distance) as travelled_distance
    from Rides
    group by user_id
)

select 
    u.name as name,
    coalesce(t1.travelled_distance, 0) as travelled_distance
from Users u left join t1 on u.id = t1.user_id
order by travelled_distance desc, name 
