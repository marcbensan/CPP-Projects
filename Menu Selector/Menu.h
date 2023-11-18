/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#define MAX_MENU_CONTENT 15

#include <iostream>

namespace sdds {

	class Menu {
		char* m_content;
		int m_numOfOptions;

	public:
		Menu(const char* content = nullptr);
		~Menu();

		unsigned int run() const;

		//getters
		int getInt();
		const char* getContent();
	};

}
#endif