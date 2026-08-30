CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
    if n <= 0 then
        return QUERY select null::int; --returns the result set
        return; --breaks the function
    end if;
  RETURN QUERY (
    select(
        select distinct Employee.salary
        from Employee
        order by Employee.salary desc
        limit 1 offset n-1 --offset from top that it 1 to n-1th position
    )
  );
END;
$$ LANGUAGE plpgsql;
