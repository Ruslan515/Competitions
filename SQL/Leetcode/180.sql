-- https://leetcode.com/problems/consecutive-numbers/
select
    num as ConsecutiveNums
from (
    select
        id,
        num,
        lag(num, 1) over () as lag1,
        lag(num, 2) over () as lag2
    from Logs) t1
where num = lag1 and num = lag2 and lag1 = lag2;
