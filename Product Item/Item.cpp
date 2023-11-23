/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-18
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "Item.h"

using namespace std;

namespace sdds {

	Item::Item() {
		m_sku = 0;
		m_price = 0;
		m_quantity = 0;
		m_neededQty = 0;
		m_desc = nullptr;
		m_Linear = false;
	}

	Item::Item(const Item& other) {
		m_price = other.m_price;
		m_quantity = other.m_quantity;
		m_neededQty = other.m_neededQty;
		m_Linear = other.m_Linear;
		m_sku = other.m_sku;

		if (other.m_desc != nullptr) {
			delete[] m_desc;
			m_desc = new char[strlen(other.m_desc) + 1];
			strcpy(m_desc, other.m_desc);
		}
		else {
			m_desc = nullptr;
		}

	}

	Item& Item::operator=(const Item& other) {
		m_price = other.m_price;
		m_quantity = other.m_quantity;
		m_neededQty = other.m_neededQty;
		m_Linear = other.m_Linear;
		m_sku = other.m_sku;

		delete[] m_desc;

		m_desc = new char[strlen(other.m_desc) + 1];
		strcpy(m_desc, other.m_desc);

		return *this;

	}

	Item::~Item() {
		delete[] m_desc;
	}

	bool Item::linear() const {
		return m_Linear;
	}

	int Item::qtyNeeded() const {
		return m_neededQty;
	}

	int Item::qty() const {
		return m_quantity;
	}

	Item::operator double() const {
		return m_price;
	}

	Item::operator bool() const {
		return m_status;
	}

	int Item::operator-=(int qty) {
		return m_quantity -= qty;
	}

	int Item::operator+=(int qty) {
		return m_quantity += qty;
	}

	void Item::linear(bool isLinear) {
		m_Linear = isLinear;
	}

	void Item::clear() {
		m_status.clear();
	}

	bool Item::operator==(int sku) const {
		return m_sku == sku;
	}

	bool Item::operator==(const char* description) const {
		if (description == nullptr || m_desc == nullptr) {
			return false;
		}

		return (strstr(m_desc, description) != nullptr);
	}

	ofstream& Item::save(ofstream& ofstr) const {
		if (m_status) {
			ofstr << m_sku << "\t" << m_desc << "\t" << m_quantity << "\t" << m_neededQty << "\t"
				<< fixed << setprecision(2) << m_price << "\t";
		}

		return ofstr;
	}

	ifstream& Item::load(ifstream& ifstr) {
		delete[] m_desc;
		char tmp[1000];

		ifstr >> m_sku;
		ifstr.ignore();
		ifstr.getline(tmp, 1000, '\t');

		m_desc = new char[strlen(tmp) + 1];
		strcpy(m_desc, tmp);

		ifstr >> m_quantity;
		ifstr.ignore();

		ifstr >> m_neededQty;
		ifstr.ignore();

		ifstr >> m_price;
		ifstr.ignore(1);

		if (ifstr.fail()) {
			m_status = "Input file stream read failed!";
		}

		return ifstr;
	}

	ostream& Item::display(ostream& ostr) const {
		if (!m_status) {
			ostr << m_status;
		}
		else {
			if (m_Linear) {
				string tmpDesc = (strlen(m_desc) > 35) ? string(m_desc, 35) : m_desc; // trimmed description if needed

				ostr << setw(5) << m_sku << " | " << left << setw(35) << setfill(' ') << tmpDesc << " | " << right << setw(4) << m_quantity << " | " << right << setw(4) << m_neededQty << " | " << right << setw(7) << setprecision(2) << m_price << " |";
			}
			else { // descriptive fprmat
				double neededFunds = (m_neededQty - m_quantity) * m_price;

				ostr << "AMA Item:" << endl
					<< m_sku << ": " << m_desc << endl
					<< "Quantity Needed: " << m_neededQty << endl
					<< "Quantity Available: " << m_quantity << endl
					<< "Unit Price: $" << m_price << endl
					<< "Needed Purchase Fund: $" << fixed << setprecision(2) << neededFunds << endl;
			}
		}

		return ostr;
	}

	int Item::readSku(istream& istr) {
		bool valid = false;

		cout << "SKU: ";
		while (!valid) {
			if (!(istr >> m_sku)) {
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(100, '\n');
			}
			else if (m_sku < 40000 || m_sku > 99999) {
				cout << "Value out of range [40000<=val<=99999]: ";
			}
			else {
				valid = true;
			}
		}

		return m_sku;
	}

	istream& Item::read(istream& istr) {
		bool valid = false;

		delete[] m_desc;
		m_status.clear();

		cout << "AMA Item:" <<endl
			<< "SKU: " << m_sku << endl
			<< "Description: ";

		istr.ignore();
		char tmp[1000];
		istr.getline(tmp, 100);
		m_desc = new char[strlen(tmp) + 1];
		strcpy(m_desc, tmp);

		cout << "Quantity Needed: ";
		while (!valid) { // quantity needed validation
			if (!(istr >> m_neededQty)) {
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (m_neededQty < 1 || m_neededQty > 9999) {
				cout << "Value out of range [1<=val<=9999]: ";
			}
			else {
				valid = true;
			}
				
		}

		valid = false;
		cout << "Quantity On Hand: ";
		while (!valid) { // quantity on hand validation
			if (!(istr >> m_quantity)) {
				cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (m_quantity < 0 || m_quantity > m_neededQty) {
				cout << "Value out of range [0<=val<=" << m_neededQty << "]: ";
			}
			else {
				valid = true;
			}
		}

		valid = false;
		cout << "Unit Price: $";
		while (!valid) {

			if (!(istr >> m_price)) {
				cout << "Invalid number, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (m_price < 0.0 || m_price > 9999.0) {
				cout << "Value out of range [0.00<=val<=9999.00]: ";
			}
			else {
				valid = true;
			}
		}

		return istr;
	}



}

