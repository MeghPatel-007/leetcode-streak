# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
FROM products AS p
JOIN orders AS o
ON p.product_id = o.product_id
WHERE DATE_FORMAT(o.order_date, '%Y-%m-%d') LIKE '2020-02-%'
GROUP BY p.product_id, p.product_name
having sum(o.unit) >= 100;
