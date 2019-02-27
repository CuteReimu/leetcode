# Write your MySQL query statement below
delete from Person where Id in (select * from (select Id from Person a where exists(select 1 from Person where Email = a.Email and Id < a.Id)) b)
