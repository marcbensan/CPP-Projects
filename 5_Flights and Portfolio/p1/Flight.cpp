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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0.0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight:: operator bool()const {
        bool isValid = m_passengers > 0 && m_fuel >= (miniFuelPer * m_passengers);
        return isValid;
    }

    Flight::operator int()const {
        return m_passengers;
    }

    Flight::operator double()const {
        return m_fuel;
    }

    Flight::operator const char* ()const {
        return m_title;
    }

    bool Flight:: operator~()const {
        return (m_passengers == 0);
    }

    Flight& Flight:: operator=(Flight& other) {
        if (this != &other) {
            m_passengers = other.m_passengers;
            m_fuel = other.m_fuel;
            strcpy(m_title, other.m_title);
            other.m_passengers = 0;
            other.m_fuel = 0.0;
            strcpy(other.m_title, "EmptyPlane");
        }
        return *this;
    }

    Flight& Flight:: operator=(const int& passengers) {
        bool isValid = passengers > 0 && passengers <= Boen747Capacity;
        if (isValid) {
            m_passengers = passengers;
        }
        else {
            m_passengers = 0;
        }
        return *this;
    }

    Flight& Flight:: operator=(const double& fuel) {
        bool isValid = fuel > 0.0 && fuel < FuelTankCapacity;
        if (isValid) {
            m_fuel = fuel;
        }
        else {
            m_fuel = 0.0;
        }
        return *this;
    }

    Flight& Flight:: operator+=(const double& fuel) {
        bool isValid = fuel > 0.0 && m_fuel < FuelTankCapacity;

        if (isValid) {
            m_fuel += fuel;

            if (m_fuel >= FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }

        return *this;
    }

    Flight& Flight::operator+=(const int& passengers) {
        bool isValid = passengers > 0 && m_passengers < Boen747Capacity;
        if (isValid) {
            m_passengers += passengers;
            if (m_passengers >= Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(const double& fuel) {
        bool isValid = fuel > 0.0 && fuel < m_fuel;

        if (isValid) {

            m_fuel -= fuel;
        }

        else {
            m_fuel = 0.0;
        }

        return *this;
    }

    Flight& Flight::operator-=(const int& passengers) {
        if (passengers > 0) {
            if (m_passengers > passengers) {
                m_passengers -= passengers;
            }
            else {
                m_passengers = 0;
            }

        }
        return *this;
    }

    Flight& Flight:: operator<<(Flight& moveFrom) {
        bool validAmount = moveFrom.m_passengers > 0 && m_passengers < Boen747Capacity;

        if (*this && *moveFrom) {

            int original = m_passengers;
            if (validAmount) {
                m_passengers += moveFrom.m_passengers;

                if (m_passengers >= Boen747Capacity) {
                    m_passengers = Boen747Capacity;
                    moveFrom.m_passengers -= (Boen747Capacity - original);
                }
                else {

                    moveFrom.m_passengers -= (m_passengers - original);
                }

            }
        }

        return *this;
    }

    Flight& Flight::operator>>(Flight& moveTo) {
        bool validAmount = m_passengers > 0 && moveTo.m_passengers < Boen747Capacity;
        if (*this && *moveTo) {
            int original = moveTo.m_passengers;
            if (validAmount) {
                moveTo.m_passengers += m_passengers;

                if (moveTo.m_passengers >= Boen747Capacity) {
                    moveTo.m_passengers = Boen747Capacity;
                    m_passengers -= (Boen747Capacity - original);
                }
                else {
                    m_passengers -= (moveTo.m_passengers - original);
                }

            }
        }

        return *this;
    }

    int Flight:: operator+(const Flight& second)const { // for flights[1] and flights[3] issue
        int total;
        if (*this && *second) {
            total = (this->m_passengers + second.m_passengers);
        }
        else {
            total = 0;
        }
        return total;
    }

    int operator+=(int& left, const Flight& right) { //friend helper function
        left += right.m_passengers;
        return left;
    }
}