-- https://leetcode.com/problems/swap-salary/
# Write your MySQL query statement below
UPDATE Salary set sex = case
when sex = "m" then "f"
when sex = "f" then "m"
end;
