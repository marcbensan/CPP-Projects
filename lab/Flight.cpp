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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
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
            strcpy(m_title,title);
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
            cout << (const char *)(*this);
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

    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= m_passengers * 600;
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return static_cast<double>(m_fuel);
    }

    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator~() const {
        if (m_passengers == 0) {
            return true;
        }
        return false;
    }


    Flight& Flight::operator=(const Flight& other) {
        if (this != &other) {
            m_passengers = other.m_passengers;
            m_fuel = other.m_fuel;
            strncpy(m_title, other.m_title, sizeof(m_title));
            m_title[sizeof(m_title) - 1] = '\0';
            const_cast<Flight&>(other) = Flight();
        }
        return *this;
    }

    Flight& Flight::operator=(int passengers) {
        if (passengers > 0 && passengers <= Boen747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }

    Flight& Flight::operator=(double fuel) {
        if (fuel >= 0 && fuel <= FuelTankCapacity) {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(double fuel) {
        if (fuel > 0) {
            m_fuel += fuel;
            if (m_fuel > FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(int passengers) {
        if (passengers > 0) {
            m_passengers += passengers;
            if (m_passengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0) {
            m_fuel -= fuel;
            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(int passengers) {
        if (passengers > 0) {
            m_passengers -= passengers;
            if (m_passengers < 0) {
                m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& other) {
        if (this != &other && *this && other) {
            int spaceAvailable = Boen747Capacity - m_passengers;
            int passengersToMove = std::min(spaceAvailable, other.m_passengers);
            m_passengers += passengersToMove;
            other.m_passengers -= passengersToMove;
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& other) {
        if (this != &other && *this && other) {
            int spaceAvailable = Boen747Capacity - other.m_passengers;
            int passengersToMove = std::min(spaceAvailable, m_passengers);
            other.m_passengers += passengersToMove;
            m_passengers -= passengersToMove;
        }
        return *this;
    }

    int Flight::operator+(const Flight& other) const {
        if (*this && other) {
            return m_passengers + other.m_passengers;
        }
        return 0;
    }
}