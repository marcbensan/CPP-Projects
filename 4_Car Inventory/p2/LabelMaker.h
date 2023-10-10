/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

namespace sdds {

	class LabelMaker {
	private:
		Label* m_labels;
		int  m_noOfLabels;

	public:
		LabelMaker(int noOfLabels);
		void readLabels() const;
		void printLabels() const;
		~LabelMaker();
	};
}

#endif