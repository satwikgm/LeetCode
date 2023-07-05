# # Write your MySQL query statement below
# # Find all the classes that have at least five students.

select class from Courses
group by class
having count(student) >= 5;

# Courses table:
# +---------+----------+
# | student | class    |
# +---------+----------+
# | A       | Math     |
# | B       | English  |
# | C       | Math     |
# | D       | Biology  |
# | E       | Math     |
# | F       | Computer |
# | G       | Math     |
# | H       | Math     |
# | I       | Math     |
# +---------+----------+
# Output: 
# +---------+
# | class   |
# +---------+
# | Math    |
# +---------+
