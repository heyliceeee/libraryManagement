//
// Created by alice on 12/12/2023.
//

#ifndef LIBRARYMANAGEMENT_BOOKS_H
#define LIBRARYMANAGEMENT_BOOKS_H

#define MAX_PUBLISHINGCOMPANY 1

#define MIN_NIF 0
#define MAX_NIF 1000
#define MSG_GET_PUBLISHINGCOMPANY_NIF "Enter publishing company NIF [0-1000]: "

#define MAX_PUBLISHINGCOMPANY_NAME 31
#define MSG_GET_PUBLISHINGCOMPANY_NAME "Enter publishing company name: "

#define MAX_PUBLISHINGCOMPANY_ADDRESS 31
#define MSG_GET_PUBLISHINGCOMPANY_ADDRESS "Enter publishing company address: "


#define MAX_AUTHORS 5

#define ERROR_NO_EXISTS_AUTHOR "Author doesnt exists in list."
#define ERROR_EMPTY_AUTHOR_LIST "The Author list is empty."
#define ERROR_FULL_AUTHOR_LIST "The Author list is full."
#define ERROR_EXISTS_AUTHOR "The Author name already exists."

#define MSG_GET_AUTHOR_NIF "Enter author NIF [0-1000]: "

#define MAX_AUTHOR_NAME 31
#define MSG_GET_AUTHOR_NAME "Enter author name: "

#define MAX_AUTHOR_WEBPAGE 31
#define MSG_GET_AUTHOR_WEBPAGE "Enter author webapge: "

#define MIN_DAY 1
#define MAX_DAY 31
#define MSG_GET_AUTHOR_DATEOFBIRTH_DAY "Enter the date of birth day: "

#define MIN_MONTH 1
#define MAX_MONTH 12
#define MSG_GET_AUTHOR_DATEOFBIRTH_MONTH "Enter the date of birth month: "

#define MIN_YEAR 1900
#define MAX_YEAR 2023
#define MSG_GET_AUTHOR_DATEOFBIRTH_YEAR "Enter the date of birth year: "


#define MAX_BOOKS 50

#define ERROR_NO_EXISTS_BOOK "Book doesnt exists in list."
#define ERROR_EMPTY_BOOK_LIST "The book list is empty."
#define ERROR_FULL_BOOK_LIST "The book list is full."
#define ERROR_EXISTS_BOOK "The book ISBN already exists."

#define MIN_BOOK_ISBN 0
#define MAX_BOOK_ISBN 1000
#define MSG_GET_BOOK_ISBN "Enter book ISBN [0-1000]: "

#define MSG_GET_BOOK_PUBLICATIONDATE_DAY "Enter the publication date day: "
#define MSG_GET_BOOK_PUBLICATIONDATE_MONTH "Enter the publication date month: "
#define MSG_GET_BOOK_PUBLICATIONDATE_YEAR "Enter the publication date year: "

#define MAX_BOOK_TITLE 31
#define MSG_GET_BOOK_TITLE "Enter book title: "

#define MSG_GET_BOOK_TYPE "Enter book type [1.FICTION  2.TECHNICIAN  3.ROMANCE  4.STUDY]: "


typedef struct
{
    int nif;
    char name[MAX_PUBLISHINGCOMPANY_NAME];
    char address[MAX_PUBLISHINGCOMPANY_ADDRESS];
} PublishingCompany;
typedef struct
{
    int count;
    PublishingCompany publishCompanies[MAX_PUBLISHINGCOMPANY];
} PublishCompanies;

typedef struct
{
    int day, month, year;
} Date;
typedef struct
{
    int nif;
    char name[MAX_AUTHOR_NAME];
    char webpage[MAX_AUTHOR_WEBPAGE];
    Date dateOfBirth;
} Author;
typedef struct
{
    int count;
    Author authors[MAX_AUTHORS];
} Authors;


typedef enum
{
    FICTION, TECHNICIAN, ROMANCE, STUDY
} Type;
typedef struct
{
    int isbn;
    Date publicationDate;
    char title[MAX_BOOK_TITLE];
    Type type;
    PublishingCompany publishingCompany;
    Author authors[MAX_AUTHORS];
} Book;
typedef struct
{
    int count;
    Book books[MAX_BOOKS];
} Books;


void insertBooks(Books *books);
void printBooks(Books books);
void printAuthors(Authors authors);
void printPublishCompanies(PublishCompanies publishCompanies);

void findBooks(Books books);

#endif //LIBRARYMANAGEMENT_BOOKS_H
