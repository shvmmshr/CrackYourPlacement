# Write your MySQL query statement below
SELECT customer_id , count(Visits.visit_id) as count_no_trans FROM Visits
LEFT JOIN Transactions 
ON Visits.visit_id=Transactions.visit_id
WHERE transaction_id is NULL
GROUP BY Visits.customer_id;