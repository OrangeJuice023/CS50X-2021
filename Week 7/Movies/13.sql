SELECT DISTINCT people.name FROM stars
JOIN movies ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name NOT LIKE "%Kevin Bacon%" AND movies.title IN(
SELECT DISTINCT movies.title FROM stars
JOIN movies ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE birth = 1958 AND name LIKE "%Kevin Bacon%") ORDER BY name ASC LIMIT 100000000000000;