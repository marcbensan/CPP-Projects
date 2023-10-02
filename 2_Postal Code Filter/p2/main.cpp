/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*
Name: Denyl Marc Bensan
StudentID: 171309222
Course: OOP244
Professor: Hong Huang
*/

#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulationsComplete.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}