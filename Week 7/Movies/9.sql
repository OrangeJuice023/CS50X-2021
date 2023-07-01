SELECT people.name FROM stars JOIN movies on stars.movie_id = movies.id JOIN people ON stars.person_id = people.id WHERE movies.year LIKE "%2004%" ORDER BY people.birth ASC LIMIT 100000;