--1
SELECT title FROM movies WHERE year = 2008;
--2
SELECT birth FROM people WHERE name = "Emma Stone";
--3
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;
--4
SELECT COUNT(*) FROM ratings WHERE rating = 10.0;
--5
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;
--6
SELECT AVG(rating) FROM ratings WHERE movie_id IN(SELECT id FROM movies WHERE year = 2012);
--7
SELECT title, rating FROM movies JOIN ratings on movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title;
--8
SELECT name FROM people WHERE id IN(SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story'));
--9
SELECT DISTINCT name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE movies.year = 2004 ORDER BY people.birth
--10
SELECT DISTINCT name FROM people JOIN directors ON people.id = directors.person_id JOIN ratings ON directors.movie_id = ratings.movie_id WHERE rating >= 9.0
--11
SELECT title from movies JOIN stars ON movies.id = stars.movie_id JOIN ratings ON movies.id = ratings.movie_id WHERE stars.person_id =(SELECT id FROM people WHERE name = "Chadwick Boseman") LIMIT 5;
--12
SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Bradley Cooper" AND movies.title IN(SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Jennifer Lawrence")
--13
SELECT DISTINCT(name) FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE movies.title IN(SELECT distinct(movies.title) FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Kevin Bacon" AND people.birth = 1958) AND people.name != "Kevin Bacon";
