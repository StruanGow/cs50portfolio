SELECT name FROM songs; --initial query
SELECT name FROM songs ORDER BY tempo; --ordered by tempo
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5; --top 5 longest songs
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75; --songs with high values
SELECT AVG(energy) FROM songs; --calculating averages
SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Post Malone"); --nesting queries
SELECT AVG(energy) FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Drake"); --nesting queries and calculating averages
SELECT name FROM songs WHERE name LIKE "%feat.%"; --searching fields for specific values
