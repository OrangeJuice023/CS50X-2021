
SELECT people.name FROM stars JOIN movies on stars.movie_id = movies.id JOIN people ON stars.person_id = people.id WHERE title LIKE "Toy Story" ORDER BY name ASC LIMIT 100000;