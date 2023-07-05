select customer_id from customer 
group by customer_id
having count(distinct product_key) = (select count(*) from product);

# Customer table:
# +-------------+-------------+
# | customer_id | product_key |
# +-------------+-------------+
# | 1           | 5           |
# | 2           | 6           |
# | 3           | 5           |
# | 3           | 6           |
# | 1           | 6           |
# +-------------+-------------+
# Product table:
# +-------------+
# | product_key |
# +-------------+
# | 5           |
# | 6           |
# +-------------+
# Output: 
# +-------------+
# | customer_id |
# +-------------+
# | 1           |
# | 3           |
# +-------------+
