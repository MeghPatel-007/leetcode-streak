-- Write your PostgreSQL query statement below
with logs1 as ( -- makes a temporary table
    select id,num,lag(num) over (order by id) as prev -- it lags the column from 1 behind
    from logs
),logs2 as (
    select id,num,prev,lag(prev) over (order by id) as prev1
    from logs1
)
select distinct num as "ConsecutiveNums"
from logs2
where num = prev and prev = prev1;
