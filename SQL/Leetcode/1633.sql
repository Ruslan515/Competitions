-- https://leetcode.com/problems/percentage-of-users-attended-a-contest/
with t1 as
    (
        select
            count(*) as cnt
        from Users
    )
select
    contest_id,
    round(100.0 * count(*) / (
        select cnt from t1
        ), 2) as percentage
from Register
group by contest_id
order by percentage desc, contest_id
