# Write your MySQL query statement below
SELECT e.name,b.bonus 
FROM employee as e LEFT JOIN bonus as B
ON e.empId=b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;