/* Write your T-SQL query statement below */
select email from person as p
group by p.email
Having Count(*) > 1
