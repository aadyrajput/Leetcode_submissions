# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) as unit
FROM Products as p INNER JOIN Orders as o
WHERE p.product_id=o.product_id AND MONTH(o.order_date)=02 AND YEAR(o.order_date)=2020
GROUP BY o.product_id HAVING SUM(o.unit)>=100;