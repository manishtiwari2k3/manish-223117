# Write your MySQL query statement below
SELECT(
SELECT MAX(salary) from Employee
WHERE salary < (SELECT MAX(salary) from Employee))
AS SecondHighestSalary