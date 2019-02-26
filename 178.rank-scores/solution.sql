# Write your MySQL query statement below
select Scores.Score, Rank from Scores left join (select distinct(Score) a, (select count(distinct(Score)) from Scores where Score >= a) Rank from Scores group by Score) e on Scores.Score = e.a order by Score desc
