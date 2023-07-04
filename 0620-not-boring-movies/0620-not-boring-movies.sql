select * from Cinema
where mod(id,2)=1 and description!='boring'
order by rating desc;

# Cinema table:
# +----+------------+-------------+--------+
# | id | movie      | description | rating |
# +----+------------+-------------+--------+
# | 1  | War        | great 3D    | 8.9    |
# | 2  | Science    | fiction     | 8.5    |
# | 3  | irish      | boring      | 6.2    |
# | 4  | Ice song   | Fantacy     | 8.6    |
# | 5  | House card | Interesting | 9.1    |
# +----+------------+-------------+--------+
# Output: 
# +----+------------+-------------+--------+
# | id | movie      | description | rating |
# +----+------------+-------------+--------+
# | 5  | House card | Interesting | 9.1    |
# | 1  | War        | great 3D    | 8.9    |
# +----+------------+-------------+--------+
