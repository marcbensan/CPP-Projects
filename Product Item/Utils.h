/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
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
// Date:
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);

        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);

    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H