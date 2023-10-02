/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <iostream>

namespace sdds {

   bool openFile(const char filename[]);

   void closeFile();

   int noOfAll();

   int noOfMatches(const char* input);

   bool read(char* line, char*& name);

   bool read(char* line, int& populationNum);

}
#endif // !SDDS_FILE_H_
