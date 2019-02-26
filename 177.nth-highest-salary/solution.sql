CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
RETURN (
    # Write your MySQL query statement below.
      select (select distinct(Salary) from Employee e where N = (select count(distinct(Salary)) from Employee where Salary >= e.Salary)) as SecondHighestSalary
    );
END
