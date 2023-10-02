/***********************************************************************
// OOP244 Workshop #2 lab (part 1): tester program
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
Course: OOP
Prof: Hong Huang
*/

#include "Employee.h"
using namespace sdds;
int main() {
    if (load()) {
        display();
    }

    deallocateMemory();
    
   return 0;
}