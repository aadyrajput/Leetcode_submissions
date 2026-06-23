# Write your MySQL query statement below
SELECT distinct a.num as ConsecutiveNums FROM 
Logs as a INNER JOIN Logs as b ON a.id+1=b.id AND a.num=b.num
INNER JOIN Logs as c ON b.id+1=c.id AND b.num=c.num;