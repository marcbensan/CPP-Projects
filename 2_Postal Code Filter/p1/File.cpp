/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");  
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(FILE* fptr, char*& name)
   {
       char newChar[128];

       if (fscanf(fptr, "%127[^\n]\n", newChar) == 1) {
           name = new char[strlen(newChar) + 1];
           strcpy(name, newChar);
           return true;
       }
       else {
           name = nullptr;
           return false;
       }
   }

   bool read(FILE* fptr, int& employeeNum) 
   {
       if (fscanf(fptr, "%d,", &employeeNum) == 1)
       {
           return true;
       }
       else 
       {
           return false;
       }
   }
   bool read(FILE* fptr, double& employeeSalary) 
   {
       if (fscanf(fptr, "%lf,", &employeeSalary) == 1)
       {
           return true;
       }
       else
       {
           return false;
       }
   }

}