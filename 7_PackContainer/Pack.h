/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <iostream>
#include "Container.h"

using namespace std;

namespace sdds {

	class Pack : public Container{
		int m_unitSize;

	public:
		Pack(const char* content = "", int size = 0, int unitSize = 330, int numOfUnits = 0);
		int operator+=(int value);
		int operator-=(int value);

		int unit() const;
		int noOfUnits() const;
		int size() const;

		void clear(int size, int unitSize, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);
	};

	ostream& operator<<(ostream& ostr, Pack& p);
	istream& operator>>(istream& istr, Pack& p);

}
#endif