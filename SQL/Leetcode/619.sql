-- https://leetcode.com/problems/biggest-single-number/
# Write your MySQL query statement below
with t1 as (
    select
        num,
        count(*)
    from MyNumbers
    group by num
    having count(*) = 1
)
select
    coalesce(max(num), null) as num
from t1
