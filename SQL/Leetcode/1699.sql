-- https://leetcode.com/problems/number-of-calls-between-two-persons/
# Write your MySQL query statement below
with t1 as (
    select
        *
    from Calls
    where from_id < Calls.to_id
),
    t2 as (
    select
        to_id as from_id,
        from_id as to_id,
        duration
    from Calls
    where to_id < from_id
    ),
    t3 as (
    select
        *
    from t1
    union all
    select
        *
    from t2
    )
select
    from_id as person1,
    to_id as person2,
    count(*) as call_count,
    sum(duration) as total_duration
from t3
group by from_id, to_id
