--Runtime: 580 ms, faster than 81.92% of MySQL online submissions for Delete Duplicate Emails.
delete from Person where Id in (select * from ( select p1.Id from Person p1 join Person p2 on p1.Id > p2.Id and p1.Email = p2.Email) t )

--
DELETE p1 FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id