# # Write your MySQL query statement below

select p.project_id , round(sum(e.experience_years) / count(e.employee_id) , 2) as average_years
from project p join employee e
on p.employee_id = e.employee_id
group by p.project_id;

# Project table:
# +-------------+-------------+
# | project_id  | employee_id |
# +-------------+-------------+
# | 1           | 1           |
# | 1           | 2           |
# | 1           | 3           |
# | 2           | 1           |
# | 2           | 4           |
# +-------------+-------------+
# Employee table:
# +-------------+--------+------------------+
# | employee_id | name   | experience_years |
# +-------------+--------+------------------+
# | 1           | Khaled | 3                |
# | 2           | Ali    | 2                |
# | 3           | John   | 1                |
# | 4           | Doe    | 2                |
# +-------------+--------+------------------+
# Output: 
# +-------------+---------------+
# | project_id  | average_years |
# +-------------+---------------+
# | 1           | 2.00          |
# | 2           | 2.50          |
# +-------------+---------------+
