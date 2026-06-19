# Write your MySQL query statement below
SELECT distinct r.contest_id,ROUND((count(r.user_id)*100)/(select count(user_id) from Users),2)
AS percentage FROM
Users as u RIGHT JOIN Register as r
ON u.user_id=r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC,contest_id;
