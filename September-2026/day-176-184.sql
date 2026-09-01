WITH max_salary AS (
    SELECT departmentId, MAX(salary) AS ms
    FROM Employee
    GROUP BY departmentId
)
SELECT dp.name as "Department", e.name as "Employee", e.salary as "Salary"
FROM Employee AS e
JOIN max_salary AS d
    ON e.departmentId = d.departmentId
    AND e.salary = d.ms
JOIN Department AS dp
    ON d.departmentId = dp.id;
