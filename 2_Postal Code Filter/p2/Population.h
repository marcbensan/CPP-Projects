/**
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
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

#ifndef SDDS_POPULATIONH
#define SDDS_POPULATIONH

#include "File.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {

    struct Populations {
        char* postalCode;
        int populationAmount;
    };

    void sort();

    bool startsWith(const char* cString, const char* subString);

    bool getPostalCode(char* postal_code_prefix);

    bool load(const char* filename, const char* partial_postal_code_prefix);

    void display(const Populations& population);

    void display();

    void deallocateMemory();

}
#endif // SDDS_POPULATIONH