-- https://leetcode.com/problems/rank-scores/
select
    score,
    DENSE_RANK() over(order by score desc) as `rank`
from Scores
order by score desc
