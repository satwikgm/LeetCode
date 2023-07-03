# # Write your MySQL query statement below

select teacher_id , count(distinct subject_id) as cnt
from Teacher
group by teacher_id;

# Teacher table:
# +------------+------------+---------+
# | teacher_id | subject_id | dept_id |
# +------------+------------+---------+
# | 1          | 2          | 3       |
# | 1          | 2          | 4       |
# | 1          | 3          | 3       |
# | 2          | 1          | 1       |
# | 2          | 2          | 1       |
# | 2          | 3          | 1       |
# | 2          | 4          | 1       |
# +------------+------------+---------+
# Output:  
# +------------+-----+
# | teacher_id | cnt |
# +------------+-----+
# | 1          | 2   |
# | 2          | 4   |
# +------------+-----+
