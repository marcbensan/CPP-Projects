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
#include <cstring>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"
#include "Menu.h"

using namespace std;

namespace sdds {

	unsigned int AidMan::displayMenu() const {
		Date date;

		cout << "Aid Management System" << endl;
		cout << "Date: " << date << endl;
		if (m_fileName) {
			cout << "Data file: " << m_fileName << '\n' << endl;
		}
		else {
			cout << "Data file: No file\n" << endl;
		}

		return menu.run();
	}

	AidMan::AidMan(const char* filename) : menu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
		if (filename == nullptr) {
			m_fileName = nullptr;
		}

		else {
			m_fileName = new char[strlen(filename) + 1];
			strcpy(m_fileName, filename);
		}
	}

	AidMan::~AidMan() {
		delete[] m_fileName;
		m_fileName = nullptr;
	}

	void AidMan::run() {
		string menuOptions[MAX_MENU_CONTENT];
		bool valid = false;
		int numOfOptions = menu.getInt();
		const char* content = menu.getContent();

		while (!valid) {
			unsigned int input = displayMenu();

			if (input == 0) {
				cout << "Exiting Program!" << endl;
				break;
			}

			for (int i = 0; i < numOfOptions; i++) {

				if (!menuOptions[i].empty()) {
					break;
				}
				const char* nextItem = strchr(content, '\t');;

				if (nextItem) {
					menuOptions[i] = string(content, nextItem - content);
					content = nextItem + 1;
				}
				else {
					menuOptions[i] = content;
				}
			}

			cout << "\n****" << menuOptions[input - 1]  << "****\n" << endl;
		}
	}
}