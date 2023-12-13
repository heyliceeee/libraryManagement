//
// Created by alice on 12/12/2023.
//

#include <string.h>
#include "input.h"
#include "stdio.h"

#define INVALID_VALUE "The value entered is invalid."
#define VALID_VALUE "The value entered is valid."


/**
 * clean input buffer
 */
void cleanInputBuffer()
{
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {}
}


/**
 * get integer value
 * @param minValue minimum value
 * @param maxValue maximum value
 * @param msg question
 * @return integer value
 */
int getInt(int min, int max, char *msg)
{
    int number, firstTime = 1;

    do
    {
        printf(" %s", msg);
        scanf("%d", &number);

        if(firstTime == 0) //if not first time question the value
        {
            puts(INVALID_VALUE);
            cleanInputBuffer();
        }

        firstTime = 0;
        cleanInputBuffer();

    } while (number < min || number > max);

    return number;
}

/**
 * read string
 * @param string string read
 * @param length length of the string
 * @param msg question
 */
void readString(char *string, int length, char *msg)
{
    printf("%s", msg);

    if(fgets(string, length, stdin) != NULL)
    {
        int len = strlen(string) - 1;

        if(string[len] == '\n')
        {
            string[len] = '\0';
        }
        else
        {
            cleanInputBuffer();
        }
    }
}

/**
 * read an enumeration
 * @param msg question
 * @return enumeration
 */
Type readEnum(char *msg)
{
    int typeValue;

    do
    {
        printf(" %s", msg);
        scanf("%d", &typeValue);

        if (typeValue < FICTION || typeValue > STUDY)
        {
            puts(INVALID_VALUE);
            cleanInputBuffer();
        }

    } while (typeValue < FICTION || typeValue > STUDY);

    cleanInputBuffer();

    return (Type)(typeValue-1);
}