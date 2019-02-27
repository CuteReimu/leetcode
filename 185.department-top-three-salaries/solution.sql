# Write your MySQL query statement below
select Department.Name Department, b.Name Employee, b.Salary from (select Name, Salary, DepartmentId from Employee a where 3 >= (select count(distinct Salary) from Employee where DepartmentId = a.DepartmentId and Salary >= a.Salary)) b inner join Department on b.DepartmentId = Department.Id
