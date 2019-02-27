# Write your MySQL query statement below
select Id from Weather a where Temperature > (select Temperature from Weather where TIMESTAMPDIFF(DAY, RecordDate, a.RecordDate) = 1)
