-- Write your PostgreSQL query statement below
select distinct w2.id
from Weather as w1
join Weather as w2
on w1.recordDate = w2.recordDate - interval '1 day'
where w2.temperature > w1.temperature;
