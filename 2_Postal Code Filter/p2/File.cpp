/**
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
**/
/*
Name: Denyl Marc Bensan
StudentID: 171309222
Course: OOP244
Professor: Hong Huang
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include "File.h"
#include "Population.h"

namespace sdds {

    FILE* fptr;

    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() 
    {
        if (fptr) fclose(fptr);
    }

    int noOfAll() 
    {
        int all = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) 
        {
            all += (ch == '\n');
        }
        rewind(fptr);
        return all;
    }

    int noOfMatches(const char* input) 
    {
        int matches = 0;
        char line[100];

        while (fgets(line, sizeof(line), fptr) != NULL)
        {
            if (strstr(line, input) != NULL) 
            {
                matches++;
            }
        }

        rewind(fptr);
        return matches;
    }

    bool read(char* line, char*& name)
    {
        char newChar[128];

        if (sscanf(line, "%127[^,]", newChar) == 1)
        {
            name = new char[strlen(newChar) + 1];
            strcpy(name, newChar);
            return true;
        }
        else {
            name = nullptr;
            return false;
        }
    }

    bool read(char* line, int& populationNum) 
    {
        if (sscanf(line, "%*[^,],%d", &populationNum) == 1)
        {
            return true;
        }

        return false;
    }

}