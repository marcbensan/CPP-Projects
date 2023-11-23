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
#include "iProduct.h"

using namespace std;

namespace sdds {

	ostream& operator<<(ostream& ostr, const iProduct& product) {
		return product.display(ostr);
	}

	istream& operator>>(istream& istr, iProduct& product) {
		return product.read(istr);
	}

}