/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include <iostream>
#include "Menu.h"

using namespace std;

namespace sdds {
	class AidMan {
		char* m_fileName;
		Menu menu;

		unsigned int displayMenu() const;

	public:
		AidMan(const char* filename);
		~AidMan();

		void run();
	};
}
#endif