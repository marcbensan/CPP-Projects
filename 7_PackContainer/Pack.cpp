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
#include "Pack.h"

using namespace std;

namespace sdds {

	Pack::Pack(const char* content, int size, int unitSize, int numOfUnits) :
		Container(content, size* unitSize, numOfUnits* unitSize) {
		if (unitSize > 0) {
			m_unitSize = unitSize;
		}
		else {
			Container::setEmpty();
			m_unitSize = 0;
		}
	}

	int Pack::operator+=(int value) {
		int amount = value * m_unitSize;
		int added = Container::operator+=(amount);

		return added / m_unitSize;
	}

	int Pack::operator-=(int value) {
		int amount = value * m_unitSize;
		int removed = Container::operator-=(amount);

		return removed / m_unitSize;
	}

	int Pack::unit() const {
		return m_unitSize;
	}

	int Pack::noOfUnits() const {
		return volume() / m_unitSize;
	}

	int Pack::size() const {
		return capacity() / m_unitSize;
	}

	void Pack::clear(int size, int unitSize, const char* content){
		if (unitSize > 0) {
			m_unitSize = unitSize;
			Container::clear(size * unitSize, content);
		}
		else {
			Container::setEmpty();
		}
	}

	ostream& Pack::print(ostream& ostr) {
		if (*this) {
			Container::print(ostr);
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		
		return ostr;
	}

	istream& Pack::read(istream& istr) {
		int input;

		if (!*this) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
		}

		else if (noOfUnits() == size()) {
			istr.ignore();
			cout << "Pack is full!, press <ENTER> to continue..." << endl;
		}

		else {
			bool valid = false;
			int maxValue = size() - noOfUnits();

			cout << "Add to ";
			print(cout);
			cout << '\n' << "> ";

				while (!valid) {
					istr >> input;

					if (input > size()) {
						cout << "Invalid Integer, retry: ";
					}

					else if (input < 1 || input > maxValue) {
						cout << "Value out of range [1<=val<=" << maxValue << "]: ";
					}

					else {
						valid = true;
					}
				}

			input = *this += input;
			cout << "Added " << input << endl;
		}

		return istr;
	}

	ostream& operator<<(ostream& ostr, Pack& p) {
		return p.print(ostr);
	}

	istream& operator>>(istream& istr, Pack& p) {
		return p.read(istr);
	}
}