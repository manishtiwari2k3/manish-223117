# Write your MySQL query statement below
SELECT(
SELECT MAX(salary) from Employee
WHERE salary NOT IN (SELECT MAX(salary) from Employee))
AS SecondHighestSalary