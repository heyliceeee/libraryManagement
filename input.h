//
// Created by alice on 12/12/2023.
//

#ifndef LIBRARYMANAGEMENT_INPUT_H
#define LIBRARYMANAGEMENT_INPUT_H

#include "books.h"

int getInt(int min, int max, char *msg);
void readString(char *string, int length, char *msg);
Type readEnum(char *msg);

#endif //LIBRARYMANAGEMENT_INPUT_H
