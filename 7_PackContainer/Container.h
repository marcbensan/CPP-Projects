/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#define MAX_DESC 50
#include <iostream>

using namespace std;

namespace sdds {

	class Container {
		char m_content[MAX_DESC];
		int m_capacity;
		int m_volume;

	protected:
		void setEmpty();
		int capacity()const;
		int volume()const;

	public:
		Container(const char* content, int capacity, int volume = 0);
		int operator+=(int value);
		int operator-=(int value);
		operator bool();

		void clear(int capacity, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);
	};

	ostream& operator<<(ostream& ostr, Container& c);
	istream& operator>>(istream& istr, Container& c);


}
#endif