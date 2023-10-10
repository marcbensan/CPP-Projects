/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Label.h"

#define MAX_CHAR 71 // HAS TO BE 71 FOR NULL TERMINATOR

namespace sdds {

	using namespace std;

	Label::Label() {
		
		strcpy(m_frameArg, "+-+|+-+|");
		m_content = nullptr;
	}

	Label::Label(const char* frameArg) {
		m_content = nullptr;
		strcpy(m_frameArg, frameArg);
		
		if (frameArg == nullptr) {
			strcpy(m_frameArg, "+-+|+-+|");
		}
	}

	Label::Label(const char* frameArg, const char* content) {
		strcpy(m_frameArg, frameArg);
		m_content = new char[strlen(content) + 1];
		text(content);
	}

	Label::~Label() {
		delete[] m_content;
	}

	istream& Label::readLabel() {
		char content[MAX_CHAR];

		cout << "> ";
		cin.getline(content, MAX_CHAR, '\n'); //content will be read upto 70 chars with '\n' as the delimiter

		text(content); // replace the content with the recent content

		return cin;
	}

	ostream& Label::printLabel() const {
		if (m_content != nullptr) {
			const int labelSize = strlen(m_content) + 3; //+ 3 is to accomodate for borders

			cout << m_frameArg[0] << setfill(m_frameArg[1]) << setw(labelSize) << m_frameArg[2] << endl // prints the first char, then filled by the second, width as the labelSize and the 3rd char to finish the first line
				<< m_frameArg[7] << setfill(' ') << setw(labelSize) << m_frameArg[3] << endl // the 7th char followed by spaces dynammically by frameArgs
				<< m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl //Actual text line with " " as padding
				<< m_frameArg[7] << setfill(' ') << setw(labelSize) << m_frameArg[3] << endl
				<< m_frameArg[6] << setfill(m_frameArg[5]) << setw(labelSize) << m_frameArg[4];
		}
		return cout;
	}


	Label& Label::text(const char* content) {
		delete[] m_content;

		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);

		return *this;
	}
}