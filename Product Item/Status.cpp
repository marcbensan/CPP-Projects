/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date:
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds {

	Status::Status(const char* desc) {
		m_code = 0;

		if (desc) {
			ut.alocpy(m_desc, desc);
		}
		else {
			m_desc = nullptr;
		}
	}

	Status::Status(const Status& status)
	{

		if (status.m_desc) {
			ut.alocpy(m_desc, status.m_desc);
			m_code = status.m_code;
		}
		else {
			delete[] m_desc;
			m_desc = nullptr;
			m_code = 0;
		}
	}

	Status::~Status() {
		delete[] m_desc;
	}

	Status& Status::operator=(const char* desc) {
		if (desc) {
			ut.alocpy(m_desc, desc);
		}

		return *this;
	}

	Status& Status::operator=(int code) {
		m_code = code;

		return *this;
	}

	Status::operator int() const {
		return m_code;
	}

	Status::operator const char* () const {
		return m_desc;
	}

	Status::operator bool() const {
		return m_desc == nullptr;
	}

	Status& Status::clear() {
		if (m_desc) {
			delete[] m_desc;
			m_desc = nullptr;
			m_code = 0;
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const Status& status) {
		if (!status) {
			status.print(os);
		}
		return os;
	}

	ostream& Status::print(ostream& ostr) const {
		if (m_code == 0) {
			ostr << m_desc;
		}
		else {
			ostr << "ERR#" << m_code << ": ";
			ostr << m_desc;
		}
		return ostr;
	}


}