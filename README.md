Appointment Management System
📌 Description

This project consists of an Appointment Management System developed in C.

The program reads data from a file named entrada.csv, stores appointments in memory using structures (struct), and allows users to:

Add appointments

Remove appointments

Sort appointments using multiple criteria

List appointments

Automatically save changes to the file

The system was developed according to academic requirements, including multiple sorting criteria and persistent data storage.

🗂 Data Structure

Each appointment contains the following fields:

Year

Month

Day

Hour

Minute

Duration (in hours)

Priority (1 to 5)

Name

Description

Location

All data is stored using a structured data type (struct).

Data Input

Appointments are automatically loaded from the file:

entrada.csv
📋 Features

The system provides the following menu options:

Add appointment

Remove appointment

Sort by date

Sort by date and time

Sort by date and priority

Sort by location, priority, and duration (descending)

List appointments

Exit

Sorting Criteria
✔ Sort by Date

Ascending order by:

Year

Month

Day

✔ Sort by Date and Time

Ascending order by:

Year

Month

Day

Hour

Minute

✔ Sort by Date and Priority

Sorted by:

Year

Month

Day

Priority (higher priority first)

✔ Sort by Location, Priority, and Duration (Descending)

Sorted by:

Location (alphabetical order)

Priority (higher first)

Duration (longer first)

Data Persistence

Whenever an appointment is added or removed, the file entrada.csv is automatically updated.

This ensures that all data remains saved even after the program is closed.
