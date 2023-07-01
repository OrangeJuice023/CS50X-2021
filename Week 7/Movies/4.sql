SELECT DISTINCT(COUNT(*)) FROM movies JOIN ratings on movies.id = ratings.movie_id WHERE ratings.rating LIKE "%10.0%" ORDER BY ratings.rating ASC LIMIT 100000000000;
