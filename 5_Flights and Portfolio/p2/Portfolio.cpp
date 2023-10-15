/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
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


#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio& Portfolio::operator+=(double value) {
        bool hasNumber = *this && value >= 0;
        if (hasNumber) {
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double value) {
        bool hasNumber = *this && value >= 0;
        if (hasNumber) {
            m_value -= value;
        }
        return *this;
    }

    bool Portfolio::operator~() const {
        return m_value < 0;
    }

    Portfolio& operator<<(Portfolio& current, Portfolio& other) {
        bool canTransfer = &current != &other && current && other;
        if (canTransfer) {
            current.m_value += other.m_value;
            other.emptyPortfolio();
        }
        return current;
    }

    Portfolio& operator>>(Portfolio& current, Portfolio& other) {
        if (&current != &other && current && other) {
            other.m_value += current.m_value;
            current.emptyPortfolio();
        }
        return other;
    }

    double operator+(const Portfolio& current, const Portfolio& other) {
        double sum = 0.0;
        if (current) {
            sum += current.m_value;
        }
        if (other) {
            sum += other.m_value;
        }
        return sum;
    }

    double& operator+=(double& current, const Portfolio& other) {
        if (other) {
            current += other.m_value;
        }
        return current;
    }

    ostream& operator<<(ostream& cout, const Portfolio& portfolio) {
        cout << "Stock: " << portfolio.operator const char* () << ", Value: " << portfolio.operator double() << ", Type: " << portfolio.operator char();
        return cout;
    }

    Portfolio::operator bool() const {
        auto charType = m_type == 'V' || m_type == 'G' || m_type == 'I';
        return charType;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

}