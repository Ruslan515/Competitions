-- https://leetcode.com/problems/delete-duplicate-emails/submissions/
# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete t1 from Person t1, Person t2
where t1.email = t2.email and t1.id > t2.id;
