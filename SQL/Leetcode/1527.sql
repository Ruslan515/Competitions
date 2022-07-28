-- https://leetcode.com/problems/patients-with-a-condition/
# Write your MySQL query statement below
select
*
from Patients
where conditions like '% DIAB1%' or conditions like 'DIAB1%';


