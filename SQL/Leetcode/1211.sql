-- https://leetcode.com/problems/queries-quality-and-percentage/
select
    query_name,
    round(avg(1.0 * rating / position), 2) as quality,
    round(100.0 * sum(if(rating < 3, 1, 0)) / count(*), 2) as poor_query_percentage
from Queries
group by query_name
