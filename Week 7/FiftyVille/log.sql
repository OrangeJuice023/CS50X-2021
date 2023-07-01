-- Keep a log of any SQL queries you execute as you solve the mystery.
.schema
.tables
.schema crime_scene_reports
-- take a look at the crime scene reports on different fields
SELECT DISTINCT description FROM crime_scene_reports WHERE crime_scene_reports.day LIKE "%28%" AND crime_scene_reports.month LIKE "%7%" AND crime_scene_reports.year LIKE "%2020%" AND crime_scene_reports.street LIKE "%Chamberlin Street%"
ORDER BY description ASC LIMIT 100000000;
-- sees all the catalogs of happenings in the chamberlin street, seems a little pedantic but just to be sure
SELECT * FROM crime_scene_reports WHERE crime_scene_reports.street LIKE "%Chamberlin Street%" AND crime_scene_reports.year LIKE "%2020%" ORDER BY id ASC LIMIT 10000000000;
-- since the reports mention that the crime took place in 10:15, et's take a look
SELECT * FROM courthouse_security_logs WHERE courthouse_security_logs.day LIKE "%28%" AND courthouse_security_logs.month LIKE "%7%" AND courthouse_security_logs.year LIKE "%2020%" AND courthouse_security_logs.hour LIKE "%10%" ORDER BY id 
ASC LIMIT 1000000000;
--it's interesting to see that there are some license plates, let's try to see all of it and since it says that a crime was reported at 10:15 am, let's put it as requirements
SELECT * FROM people JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate WHERE day LIKE "%28%" AND month LIKE  "%7%" AND year LIKE "%2020%" AND hour LIKE "%10%" AND minute <= "20" ORDER BY name
ASC LIMIT 1000000000;
-- selects all interviews catalog on the day
SELECT * FROM interviews WHERE interviews.day LIKE "%28%" AND interviews.month LIKE "%7%" AND interviews.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
--checks all the court house security logs 
SELECT * FROM courthouse_security_logs WHERE courthouse_security_logs.day LIKE "%28%" AND courthouse_security_logs.month LIKE "%7%" AND courthouse_security_logs.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
-- checks atm transactions catagalog
SELECT * FROM atm_transactions WHERE atm_transactions.day LIKE "%28%" AND atm_transactions.month LIKE "%7%" AND atm_transactions.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
--check phone call logs on that day
SELECT caller FROM phone_calls WHERE phone_calls.day LIKE "%28%" AND phone_calls.month LIKE "%7%" AND phone_calls.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
SELECT * FROM phone_calls WHERE phone_calls.day LIKE "%28%" AND phone_calls.month LIKE "%7%" AND phone_calls.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
--check flights catalog
SELECT * FROM flights WHERE flights.day LIKE "%28%" AND flights.month LIKE "%7%" AND flights.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
-- delves deeper into the interviews
SELECT name, transcript FROM interviews WHERE interviews.day LIKE "%28%" AND interviews.month LIKE "%7%" AND interviews.year LIKE "%2020%" ORDER BY id ASC LIMIT 1000000000;
-- filter the interviews by commonality: Courthouse
SELECT name, transcript FROM interviews WHERE interviews.day LIKE "%28%" AND interviews.month LIKE "%7%" AND interviews.year LIKE "%2020%" AND interviews.transcript LIKE "%courthouse%" ORDER BY name ASC LIMIT 1000000000;
-- sees their transcript 
--Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.
--Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

--let's attend to Ruth's interview first, since the crime happened in 10:15am and Ruth said that the thieft left within 10 minutes of the theft, let's add another 10 mins
SELECT * FROM people JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate WHERE day LIKE "%28%" AND month LIKE  "%7%" AND year LIKE "%2020%" AND hour LIKE "%10%" AND minute >= 13 AND MINUTE < 26  AND activity = "exit"
ORDER BY name ASC LIMIT 1000000000;
-- suspects so far
--Amber
--Danielle
--Elizabeth
---Ernest
--Evelyn
--Patrick
--Roger
--Russell

--let's now then attend to Eugene's interview let's first check since now we know that the location is in Fifer Street, let's try to check the atm account logs there
SELECT * FROM atm_transactions WHERE atm_transactions.day LIKE "%28%" AND atm_transactions.month LIKE "%7%" AND atm_transactions.year LIKE "%2020%" and atm_location LIKE "%Fifer Street%" AND transaction_type = "withdraw" 
ORDER BY id ASC LIMIT 1000000000;
-- seeing this, we should cross match this to who ever owns these accounts
SELECT name from bank_accounts JOIN  atm_transactions ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON bank_accounts.person_id = people.id WHERE atm_transactions.day
LIKE "%28%" AND atm_transactions.month LIKE "%7%" AND atm_transactions.year LIKE "%2020%" and atm_location LIKE "%Fifer Street%" AND transaction_type = "withdraw" ORDER BY name ASC LIMIT 1000000000;
-- new suspects
--name
--Bobby
--Danielle
--Elizabeth
--Ernest
--Madison
--Roy
--Russell
--Victoria

-- Common Names (possible suspects): Ernest, Danielle, Elizabeth, Russel
-- now let's attend to Raymond
-- let's first check who made calls on that exact time to have prior knowledge
SELECT DISTINCT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE phone_calls.year LIKE "%2020%" AND phone_calls.month LIKE "%7%" AND phone_calls.day LIKE "%28%" AND phone_calls.duration < "60" 
ORDER BY name ASC LIMIT 1000000000;
-- possible suspects here are: Bobby, Ernest, Evelyn, Kimberly, Madison, Roger, Russell, Victoria
-- we need to find who is in the first flight in the morning, so we need to cross match 3 tables
SELECT * FROM passengers JOIN people ON passengers.passport_number = people.passport_number WHERE passengers.flight_id = (SELECT id FROM flights WHERE flights.year LIKE "%2020%" AND flights.month LIKE "%7%" AND flights.day LIKE "%29%"
ORDER BY flights.hour, flights.minute DESC LIMIT 1);

-- new suspects
--name
--Doris
--Roger
--Ernest
--Edward
--Evelyn
--Madison
--Bobby
--Danielle
--Suspect is Ernest but there is still an accomplice

-- to check where Ernest is going, I need to connect the flights and airports table
SELECT full_name, city FROM flights JOIN airports  ON flights.destination_airport_id = airports.id WHERE flights.day LIKE "%29%" AND flights.month LIKE "%7%" AND flights.year LIKE "%2020%" ORDER BY flights.hour, flights.minute
LIMIT 1;

-- since we already know that the suspect is Ernest, we can use his phone number to track who ever received his call
SELECT * FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE phone_calls.caller LIKE "(367) 555-5533" AND phone_calls.day LIKE "%28%" AND phone_calls.duration < 60;

