select e.name
from employee as e
inner join employee as m
on e.id = m.managerid
group by e.name,e.id
having count(m.managerId) >= 5;
