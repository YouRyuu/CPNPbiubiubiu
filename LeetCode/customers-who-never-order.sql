select Name as Customers from Customers where not exists
(select * from Orders where Customers.Id = Orders.CustomerId
);

--
select Name as Customers from Customers left join Orders on Customers.Id=Orders.CustomerId where Orders.CustomerId is null