//
// Created by alice on 12/12/2023.
//

#include <stdio.h>
#include "books.h"
#include "input.h"



/**
 * return author nif if exists, otherwise return -1
 * @param authors list
 * @param nif nif
 * @return author nif if exists, otherwise return -1
 */
int findAuthor(Authors authors, int nif)
{
    int i;

    for (i=0; i < authors.count; i++)
    {
        if(authors.authors[i].nif == nif)
        {
            return nif;
        }
    }

    return -1;
}

/**
 * return author NIF if insert new author, otherwise return -1
 * @param authors list
 * @return author NIF if insert new author, otherwise return -1
 */
int insertAuthor(Authors *authors)
{
    int nif = getInt(MIN_NIF, MAX_NIF, MSG_GET_AUTHOR_NIF);

    if(findAuthor(*authors, nif) == -1)
    {
        readString((*authors).authors[(*authors).count].name, MAX_AUTHOR_NAME, MSG_GET_AUTHOR_NAME);
        readString((*authors).authors[(*authors).count].webpage, MAX_AUTHOR_WEBPAGE, MSG_GET_AUTHOR_WEBPAGE);

        (*authors).authors[(*authors).count].dateOfBirth.day = getInt(MIN_DAY, MAX_DAY, MSG_GET_AUTHOR_DATEOFBIRTH_DAY);
        (*authors).authors[(*authors).count].dateOfBirth.month = getInt(MIN_MONTH, MAX_MONTH, MSG_GET_AUTHOR_DATEOFBIRTH_MONTH);
        (*authors).authors[(*authors).count].dateOfBirth.year = getInt(MIN_YEAR, MAX_YEAR, MSG_GET_AUTHOR_DATEOFBIRTH_YEAR);


        return (*authors).count++;
    }

    return -1;
}

/**
 * insert authors in list
 * @param authors list
 */
void insertAuthors(Authors *authors)
{
    if((*authors).count < MAX_AUTHORS) //if list no full
    {
        if(insertAuthor(authors) == -1) //if no find author
        {
            puts(ERROR_EXISTS_AUTHOR);
        }
    }
    else
    {
        puts(ERROR_FULL_AUTHOR_LIST);
    }
}


/**
 * return book isbn if exists, otherwise return -1
 * @param books list
 * @param isbn isbn
 * @return book isbn if exists, otherwise return -1
 */
int findBook(Books books, int isbn)
{
    int i;

    for (i=0; i < books.count; i++)
    {
        if(books.books[i].isbn == isbn)
        {
            return isbn;
        }
    }

    return -1;
}

/**
 * return book ISBN if insert new book, otherwise return -1
 * @param books list
 * @return book ISBN if insert new book, otherwise return -1
 */
int insertBook(Books *books)
{
    int isbn = getInt(MIN_BOOK_ISBN, MAX_BOOK_ISBN, MSG_GET_BOOK_ISBN);


    if(findBook(*books, isbn) == -1) //if no find book ISBN
    {
        (*books).books[(*books).count].isbn = isbn;

        (*books).books[(*books).count].publicationDate.day = getInt(MIN_DAY, MAX_DAY, MSG_GET_BOOK_PUBLICATIONDATE_DAY);
        (*books).books[(*books).count].publicationDate.month = getInt(MIN_MONTH, MAX_MONTH, MSG_GET_BOOK_PUBLICATIONDATE_MONTH);
        (*books).books[(*books).count].publicationDate.year = getInt(MIN_YEAR, MAX_YEAR, MSG_GET_BOOK_PUBLICATIONDATE_YEAR);

        readString((*books).books[(*books).count].title, MAX_BOOK_TITLE, MSG_GET_BOOK_TITLE);

        (*books).books[(*books).count].type = readEnum(MSG_GET_BOOK_TYPE);

        readString((*books).books[(*books).count].publishingCompany.name, MAX_PUBLISHINGCOMPANY_NAME, MSG_GET_PUBLISHINGCOMPANY_NAME);
        readString((*books).books[(*books).count].publishingCompany.address, MAX_PUBLISHINGCOMPANY_ADDRESS, MSG_GET_PUBLISHINGCOMPANY_ADDRESS);

        insertAuthors((*books).books[(*books).count].authors);


        return (*books).count++;
    }

    return -1;
}

/**
 * insert books in list
 * @param books list
 */
void insertBooks(Books *books)
{
    if((*books).count < MAX_BOOKS) //if list no full
    {
        if(insertBook(books) == -1) //if no find book ISBN
        {
            puts(ERROR_EXISTS_BOOK);
        }
    }
    else
    {
        puts(ERROR_FULL_BOOK_LIST);
    }
}


