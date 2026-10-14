-- Ranked Employee
with rankedEmployee as ( -- cte
    select
    d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    dense_rank() over (partition by e.departmentId order by e.salary desc) as rnk
    from employee as e
    join department as d
    on e.departmentId = d.id
)
select Department,Employee,Salary
from rankedEmployee
where rnk <= 3;
