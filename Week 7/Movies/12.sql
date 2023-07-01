SELECT movies.title FROM stars JOIN movies ON stars.movie_id = movies.id JOIN people ON stars.person_id = people.id  WHERE people.name LIKE "%Johnny Depp%" AND movies.title IN(SELECT movies.title FROM stars JOIN movies ON stars.movie_id = movies.id JOIN people ON stars.person_id = people.id 
WHERE people.name LIKE "%Helena Bonham Carter%") ORDER BY title;
