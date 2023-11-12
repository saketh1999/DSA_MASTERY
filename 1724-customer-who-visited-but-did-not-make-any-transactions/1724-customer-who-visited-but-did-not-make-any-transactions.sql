# Write your MySQL query statement below
Select  v.customer_id,COUNT(v.visit_id) as count_no_trans
from Visits as v
left Join transactions
on v.visit_id = Transactions.visit_id
where  transaction_id is NULL
GROUP BY v.customer_id ;


