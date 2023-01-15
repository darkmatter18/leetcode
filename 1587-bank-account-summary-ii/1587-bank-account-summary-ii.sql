# Write your MySQL query statement below
SELECT Users.name AS NAME, t.balance AS BALANCE FROM Users INNER JOIN 
    (SELECT account, SUM(amount) AS balance FROM Transactions GROUP BY account HAVING balance > 10000) AS t
    ON
    Users.account = t.account;