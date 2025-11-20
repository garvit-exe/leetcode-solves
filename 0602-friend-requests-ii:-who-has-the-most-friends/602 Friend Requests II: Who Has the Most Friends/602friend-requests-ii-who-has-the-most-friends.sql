# Write your MySQL query statement below
SELECT id, count(*) num
FROM (
    SELECT requester_id id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id id
    FROM RequestAccepted
) AS base
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;