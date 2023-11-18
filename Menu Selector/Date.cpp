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
#include <iomanip>
#include "Date.h"
#include "Utils.h"
#include "Status.h"

using namespace std;

namespace sdds {

	bool Date::validate() {
		bool isValid = false;
		int currentYear;

		ut.getSystemDate(&currentYear);
		status.clear();

		if (m_year < currentYear || m_year > MAXIMUM_YEAR_VALUE) {
			status = "Invalid year in date";
			status = 1;
		}

		else if (m_month < 1 || m_month> 12) {

			status = "Invalid month in date";

			status = 2;

		}

		else if (m_day<1 || m_day > ut.daysOfMon(m_month, m_year)) {

			status = "Invalid day in date";

			status = 3;

		}
		else if (codeZero)
		{
			status = "Invalid date value";
			status = 0;
		}

		else {

			isValid = true;

		}

		return isValid;

	}

	int Date::uniqueDateValue()const {
		return m_year * 372 + m_month * 31 + m_day;
	}

	Date::Date(int year, int month, int day) {
		codeZero = false;
		m_formatted = true;
		m_year = year;
		m_month = month;
		m_day = day;
		validate();
	}

	Date::Date() {
		codeZero = false;
		m_formatted = true;
		ut.getSystemDate(&m_year, &m_month, &m_day);
	}

	bool Date::operator==(const Date& other) const {
		return this->uniqueDateValue() == other.uniqueDateValue();
	}

	bool Date::operator!=(const Date& other) const {
		return this->uniqueDateValue() != other.uniqueDateValue();
	}

	bool Date::operator<(const Date& other) const {
		return this->uniqueDateValue() < other.uniqueDateValue();
	}

	bool Date::operator>(const Date& other) const {
		return this->uniqueDateValue() > other.uniqueDateValue();
	}

	bool Date::operator<=(const Date& other) const {
		return this->uniqueDateValue() <= other.uniqueDateValue();
	}

	bool Date::operator>=(const Date& other) const {
		return this->uniqueDateValue() >= other.uniqueDateValue();
	}

	const Status& Date::state() {
		return status;
	}

	Date& Date::formatted(bool format) {
		if (!format) {
			m_formatted = false;
		}

		return *this;
	}

	Date::operator bool() const {
		return status;
	}

	ostream& Date::write(ostream& ostr) const {
		int twoDigitYear = m_year % 100;

		ostr << setfill('0');

		if (m_formatted) {
			ostr << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day;
		}

		else {
			ostr << twoDigitYear << setw(2) << m_month << setw(2) << m_day;
		}

		return ostr;
	}

	istream& Date::read(istream& istr) {
		int dateValue;

		istr >> dateValue;

		if (istr) {
			if (dateValue <= 9999) {
				int currentYear;
				ut.getSystemDate(&currentYear);
				m_year = currentYear;
				m_month = dateValue / 100;
				m_day = dateValue % 100;
			}
			else if (dateValue >= 100000 && dateValue <= 999999) {
				m_year = 2000 + (dateValue / 10000);
				m_month = (dateValue / 100) % 100;
				m_day = dateValue % 100;

			}
		}

		else {
			codeZero = true;
		}

		if (!validate()) {
			istr.setstate(ios::badbit);
		}

		return istr;
	}

	ostream& operator<<(ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	istream& operator>>(istream& istr, Date& date) {
		return date.read(istr);
	}

}