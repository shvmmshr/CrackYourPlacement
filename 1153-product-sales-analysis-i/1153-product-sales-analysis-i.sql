# Write your MySQL query statement below
SELECT Product.product_name , Sales.year , Sales.price 
FROM Product join Sales
on Product.product_id=Sales.product_id