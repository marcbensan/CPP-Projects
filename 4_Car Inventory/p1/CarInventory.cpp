/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include "CarInventory.h"

namespace sdds {
	using namespace std;

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();

		m_type = new char[strlen(type) + 1]; // + 1 to allocate for delimiter
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];

		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
	}

	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		resetInfo();

		m_type = new char[strlen(type) + 1]; // + 1 to allocate for delimiter
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];

		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;

		return *this;
	}

	void CarInventory::printInfo() const {
		cout  << "| " <<left << setw(TYPE_SPACES) << m_type //im using setw() from iomanip as shown from the main file
			 << " | " << left << setw(BRAND_AND_MODEL_SPACES) << m_brand
			 << " | " << left << setw(BRAND_AND_MODEL_SPACES) << m_model
			 << " | " << right << setw(YEAR_AND_CODE_SPACES) << m_year
			 << " | " << right << setw(YEAR_AND_CODE_SPACES) << m_code
			 << " | " << right << fixed << setprecision(2) << setw(PRICE_SPACES) << m_price
			 << " |" << endl;
	}

	bool CarInventory::isValid() const {
		bool validInv = (m_type && m_brand && m_model && m_year >= 1990 && m_code > 99 && m_price > 0);
		return validInv;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (isValid()) {
			bool isUnique = (!strcmp(m_brand, car.m_brand) && !strcmp(m_model, car.m_model) && m_year == car.m_year);
			return isUnique;
		}
		return false;
	}

	int find_similar(CarInventory car[], const int num_cars) {
		int nothingSimilar = -1;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return nothingSimilar;
	}
}