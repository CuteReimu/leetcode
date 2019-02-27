# Write your MySQL query statement below
select Name Employee from Employee a where Salary > (Select Salary from Employee where a.ManagerId = Id)
