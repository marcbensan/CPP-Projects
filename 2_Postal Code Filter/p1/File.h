/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare overloaded read function prototypes

   bool read(FILE* fptr, char*& name);

   bool read(FILE* fptr, int& employeeNum);

   bool read(FILE* fptr, double& employeeSalary);

}

#endif // !SDDS_FILE_H_