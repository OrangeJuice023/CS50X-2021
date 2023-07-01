SELECT DISTINCT people.name FROM ratings JOIN directors on directors.movie_id = ratings.movie_id JOIN people ON directors.person_id = people.id WHERE ratings.rating >= 9.0 ORDER BY name ASC LIMIT 100000000000;