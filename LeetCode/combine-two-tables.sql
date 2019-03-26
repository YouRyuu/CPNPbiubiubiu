select Person.FirstName, Person.LastName, Address.City, Address.State 
from Person
left join Address
on Person.PersonId = Address.PersonId;
考点：left join 和 right join