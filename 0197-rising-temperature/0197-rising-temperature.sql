# Write your MySQL query statement below
SELECT w.id FROM Weather as w
INNER JOIN Weather as ww
ON DATEDIFF(w.recordDate,ww.recordDATE)=1 WHERE w.temperature>ww.temperature;