-- Write your PostgreSQL query statement below
select e.name as "Employee"
from Employee as e
join Employee as m
on m.id = e.managerid
where e.salary > m.salary;
