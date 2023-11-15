/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"

using namespace std;

namespace sdds {

	Container::Container(const char* content, int capacity, int volume) {
		if (content == nullptr || volume > capacity) {
			setEmpty();
		}

		else {
			strncpy(m_content, content, MAX_DESC);
			m_content[MAX_DESC - 1] = '\0';
			m_capacity = capacity;
			m_volume = volume;
		}
	}

	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = 0;
		m_volume = 0;
	}

	int Container::capacity()const {
		return m_capacity;
	}

	int Container::volume()const {
		return m_volume;
	}

	int Container::operator+=(int value) {
		if (m_volume + value <= m_capacity) {
			m_volume += value;
		}
		else {
			value = m_capacity - m_volume;
			m_volume += value;
		}

		return value;
	}

	int Container::operator-=(int value) {
		if (m_volume - value >= 0) {
			m_volume -= value;
		}
		else {
			value = m_volume;
			m_volume = 0;
		}

		return value;
	}

	Container::operator bool() {
		return m_content[0] != '\0' && m_volume <= m_capacity;
	}

	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content) {
			strncpy(m_content, content, MAX_DESC);
			m_content[MAX_DESC - 1] = '\0';
			m_capacity = capacity;
		}
	}

	ostream& Container::print(ostream& ostr) {
		if (operator bool()) {
			ostr << m_content << ": (" << m_volume << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}

		return ostr;
	}

	istream& Container::read(istream& istr) {
		bool valid = false; // flag for validator
		int input;
		int amount;

		if (!operator bool()) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
		}
		else {
			cout << "Add to ";
			print(cout);

			while (!valid) {
				cout << '\n' << "> ";
				istr >> input;

				istr.clear();
				istr.ignore(1000, '\n');

				if (input > m_capacity) {
					cout << "Invalid Integer, retry: ";
				}

				else if (input < 1 || input > 999) {
					cout << "Value out of range [1<=val<=999]: ";
				}
				else {
					valid = true;
				}
			}

			amount = *this += input;
			cout << "Added " << amount << " CCs" << endl;
		}

		return istr;
	}

	ostream& operator<<(ostream& ostr, Container& c) {
		return c.print(ostr);
	}

	istream& operator>>(istream& istr, Container& c) {
		return c.read(istr);
	}
}