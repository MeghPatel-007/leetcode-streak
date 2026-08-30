-- Write your PostgreSQL query statement below
select a.firstName,a.lastName,b.city,b.state from Person as a
left join Address as b
on a.personId = b.personId;
