-- https://leetcode.com/problems/article-views-i/
# Write your MySQL query statement below
select
	viewer_id as id
from Views
where viewer_id = author_id
group by viewer_id
order by viewer_id
