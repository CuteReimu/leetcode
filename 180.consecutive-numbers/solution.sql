# Write your MySQL query statement below
select distinct(Num) ConsecutiveNums from (select Id, Num from `Logs` b where 2 = (select count(1) from `Logs` where Num = b.Num and (Id = b.Id + 1 or Id = b.Id - 1))) c
