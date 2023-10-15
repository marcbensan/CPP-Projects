/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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


#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       std::ostream& display() const;
       operator bool() const;
       operator double() const;
       operator char() const;
       operator const char* () const;
       bool operator~() const;

       Portfolio& operator+=(double value);
       Portfolio& operator-=(double value);

       friend Portfolio& operator<<(Portfolio& left, Portfolio& right);
       friend Portfolio& operator>>(Portfolio& left, Portfolio& right);

       friend double operator+(const Portfolio& left, const Portfolio& right);
       friend double& operator+=(double& left, const Portfolio& right);
   };

   std::ostream& operator<<(std::ostream& os, const Portfolio& portfolio);

}
#endif // SDDS_Portfolio_H_