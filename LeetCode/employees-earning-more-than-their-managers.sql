select e1.Name as Employee from Employee e1 where exists
(
select * from Employee e2 where e2.Id = e1.ManagerId and e2.Salary<e1.Salary
);

--offical answer
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
;