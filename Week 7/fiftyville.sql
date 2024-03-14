--info of crime: 2023 7 28
--SELECT year, month, day, description FROM crime_scene_reports WHERE description LIKE "%theft%";
--name of the thief first - Bruce!
SELECT name FROM people WHERE people.license_plate IN(
    SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)
    AND people.passport_number IN(SELECT passport_number FROM passengers WHERE flight_id IN(SELECT id FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute ASC LIMIT 1))
    AND people.id IN(SELECT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND transaction_type = "withdraw" AND atm_transactions.atm_location = "Leggett Street")
    AND people.phone_number IN(SELECT caller FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28);
--and where Bruce is going to: New York City
SELECT city FROM airports WHERE id IN(SELECT destination_airport_id FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute ASC LIMIT 1);
--accomplice is:
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration <= 60 AND caller = (SELECT phone_number FROM people WHERE name = "Bruce"));
