# Library Management
* [x] Insert Books
* [ ] Show all Books
* [ ] Show all Authors
* [ ] Show all Publishing Companies


| **BOOK**          |                                           |
|-------------------|-------------------------------------------|
| isbn              | int                                       |
| publicationDate   | int day, int month, int year              |
| title             | char[]                                    |
| type              | Enum[FICTION, TECHNICIAN, ROMANCE, STUDY] |
| publishingCompany | PUBLISHINGCOMPANY                         |
| authors           | AUTHOR[5]                                 |


| **PUBLISHING COMPANY** |        |
|------------------------|--------|
| nif                    | int    |
| name                   | char[] |
| address                | char[] |

| **AUTHOR**  |                              |
|-------------|------------------------------|
| nif         | int                          |
| name        | char[]                       |
| webpage     | char[]                       |
| dateOfBirth | int day, int month, int year |