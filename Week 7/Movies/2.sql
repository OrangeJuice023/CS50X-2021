SELECT DISTINCT(UPPER(people.birth)) FROM people WHERE people.name LIKE "%Emma Stone%" ORDER BY people.birth ASC LIMIT 100000000;
