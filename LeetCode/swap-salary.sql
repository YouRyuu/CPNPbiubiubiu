--1
update salary set sex = if(sex = 'm','f','m')

--2
update salary 
set sex = case 
            when sex = 'm' then 'f'
            when sex = 'f' then 'm'
          end