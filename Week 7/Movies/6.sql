SELECT DISTINCT(avg(rating)) FROM ratings WHERE movie_id IN (SELECT movies.id FROM movies WHERE movies.year LIKE "%2012%") ORDER BY ratings.rating ASC LIMIT 1000000000;
