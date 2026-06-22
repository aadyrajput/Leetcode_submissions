# Write your MySQL query statement below
SELECT user_id,concat(upper(substring(name,1,1)),lower(substring(name,2))) as name 
FROM Users
ORDER BY user_id;