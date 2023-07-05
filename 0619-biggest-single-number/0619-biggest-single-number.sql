select if(count(*)=1,num,null) as num from MyNumbers 
group by num
order by num desc
limit 1;

# +-----+
# | num |
# +-----+
# | 8   |
# | 8   |
# | 3   |
# | 3   |
# | 1   |
# | 4   |
# | 5   |
# | 6   |
# +-----+
# Output: 
# +-----+
# | num |
# +-----+
# | 6   |
# +-----+