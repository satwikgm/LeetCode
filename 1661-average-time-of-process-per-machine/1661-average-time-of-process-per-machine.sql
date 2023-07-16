# # Write your MySQL query statement below

select t1.machine_id , round(avg(t2.timestamp-t1.timestamp),3) as processing_time
from activity t1 join activity t2
on t1.machine_id=t2.machine_id and 
t1.process_id=t2.process_id and
t1.activity_type='start' and t2.activity_type='end'
group by machine_id;


# Activity table:
# +------------+------------+---------------+-----------+
# | machine_id | process_id | activity_type | timestamp |
# +------------+------------+---------------+-----------+
# | 0          | 0          | start         | 0.712     |
# | 0          | 0          | end           | 1.520     |
# | 0          | 1          | start         | 3.140     |
# | 0          | 1          | end           | 4.120     |
# | 1          | 0          | start         | 0.550     |
# | 1          | 0          | end           | 1.550     |
# | 1          | 1          | start         | 0.430     |
# | 1          | 1          | end           | 1.420     |
# | 2          | 0          | start         | 4.100     |
# | 2          | 0          | end           | 4.512     |
# | 2          | 1          | start         | 2.500     |
# | 2          | 1          | end           | 5.000     |
# +------------+------------+---------------+-----------+
# Output: 
# +------------+-----------------+
# | machine_id | processing_time |
# +------------+-----------------+
# | 0          | 0.894           |
# | 1          | 0.995           |
# | 2          | 1.456           |
# +------------+-----------------+
