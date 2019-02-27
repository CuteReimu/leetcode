# Write your MySQL query statement below
select Department.Name Department, b.Name Employee, b.Salary from (select Name, Salary, DepartmentId from Employee a where Salary = (select max(Salary) from Employee where DepartmentId = a.DepartmentId)) b inner join Department on b.DepartmentId = Department.Id
