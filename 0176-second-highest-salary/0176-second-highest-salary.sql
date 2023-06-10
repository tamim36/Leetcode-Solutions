select isnull(max(salary), null) as SecondHighestSalary from employee 
where salary < (select max(salary) from employee);