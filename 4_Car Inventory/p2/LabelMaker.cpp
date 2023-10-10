/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#include <iostream>
#include "Label.h"
#include "LabelMaker.h"

namespace sdds {

	using namespace std;

	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabels = noOfLabels;
		m_labels = new Label[m_noOfLabels];
	}

	void LabelMaker::readLabels() const {
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			m_labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels() const {
		for (int i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] m_labels;
	}
}