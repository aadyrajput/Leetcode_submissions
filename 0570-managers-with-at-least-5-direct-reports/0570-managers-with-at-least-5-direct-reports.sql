# Write your MySQL query statement below
SELECT e.name FROM
Employee as e INNER JOIN Employee as ee
ON e.id=ee.managerID GROUP BY e.id HAVING count(e.id)>=5
