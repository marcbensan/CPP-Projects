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
#include "HealthCard.h"
using namespace std;
namespace sdds {
 
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		bool isValid = (name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9);
		return isValid;
	}

	void HealthCard::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
	}

	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const {
		char nextChar = istr.peek();

		if (nextChar == ch) {
			istr.ignore();
		}

		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
		
	}

	ostream& HealthCard::printIDInfo(ostream& ostr)const {
		return ostr << m_number << '-' << m_vCode << ", " << m_sNumber;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {

		delete[] m_name;
		m_name = nullptr;
		setEmpty();

		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}

	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {
		if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			*this = hc;
		}
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard() {
		delete[] m_name;
		m_name = nullptr;
	}

	HealthCard::operator bool()const {
		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const {
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << this->m_name << ",";
				printIDInfo(ostr) << endl;
			}

			else {
				ostr << left << setw(50) << setfill('.') << m_name;
				printIDInfo(ostr);
			}
		}

		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		char name[MaxNameLength];
		long long number;
		char vCode[3];
		char stockNumber[10];

		istr.get(name, MaxNameLength, ',');

		extractChar(istr, ',');

		istr >> number;

		extractChar(istr, '-');

		istr.get(vCode, 3, ',');

		extractChar(istr, ',');

		istr.get(stockNumber, 10, '\n');

		if (!istr.fail()) {
			set(name, number, vCode, stockNumber);
		}

		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		if (hc){
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}

		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}
}
