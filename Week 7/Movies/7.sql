SELECT DISTINCT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE movies.year LIKE "%2010%" ORDER BY 2 DESC, movies.title ASC LIMIT 10000000000000000;
