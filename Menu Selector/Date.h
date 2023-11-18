/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include <iostream>
#include "Status.h"

using namespace std;
namespace sdds {
	const int MAXIMUM_YEAR_VALUE = 2030;

	class Date {
		int m_year;
		int m_month;
		int m_day;
		Status status;
		bool m_formatted;
		bool codeZero; // this will check if the code is 0 then it will print "Invalid date value".

		bool validate();
		int uniqueDateValue() const;

	public:
		Date(int year, int month, int day);
		Date();

		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator>=(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;

		const Status& state();
		Date& formatted(bool format);

		operator bool() const;

		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);

	};
	ostream& operator<<(ostream& ostr, const Date& date);
	istream& operator>>(istream& istr, Date& date);

}
#endif