# Write your MySQL query statement below
SELECT distinct teacher_id,COUNT(distinct subject_id) AS cnt
FROM Teacher GROUP BY teacher_id;