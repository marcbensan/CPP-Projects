/***********************************************************************
// Final project Milestone 2
// Module: Menu and AidMan
// File: main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#include <iostream>
#include "Menu.h"
#include "AidMan.h"
#include "Utils.h"
int main() {
   std::cout << "Enter the following to test MS2:\n abc\n 0 \n 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 0\n--------\n";
   std::cout << "Testing Invalid Menu: " << sdds::Menu("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t").run() << std::endl;
   std::cout << "-----------------------------------------" << std::endl;
   sdds::ut.testMode();
   sdds::AidMan(nullptr).run();
   sdds::AidMan("fakeFileName.csv").run();
   return 0;
}