/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;
    const int miniFuelPer = 600;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;

        operator bool()const;
        operator int()const;
        operator double()const;
        operator const char* ()const;
        bool operator~()const;

        Flight& operator=(Flight& src);
        Flight& operator=(const int& passengers);
        Flight& operator=(const double& fuel);
        Flight& operator+=(const double& fuel);
        Flight& operator+=(const int& passengers);
        Flight& operator-=(const double& fuel);
        Flight& operator-=(const int& passengers);
        Flight& operator<<(Flight& moveFrom);
        Flight& operator>>(Flight& moveTo);
        int operator+(const Flight& second)const;

        friend int operator+=(int& left, const Flight& right);

    };

}
#endif