/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;

      bool operator~() const;

      Flight& operator=(const Flight& other);
      Flight& operator=(int passengers);
      Flight& operator=(double fuel);
      Flight& operator+=(double fuel);
      Flight& operator+=(int passengers);
      Flight& operator-=(double fuel);
      Flight& operator-=(int passengers);
      Flight& operator<<(Flight& other);
      Flight& operator>>(Flight& other);
      int operator+(const Flight& other) const;
   };

}
#endif // SDDS_FLIGHT_H