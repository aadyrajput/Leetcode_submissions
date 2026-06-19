# Write your MySQL query statement below
SELECT ee.unique_id, e.name FROM Employees AS e
LEFT JOIN EmployeeUNI AS ee
ON e.id=ee.id;



