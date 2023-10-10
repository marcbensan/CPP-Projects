/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#define MAX_CHAR 71

namespace sdds {

	using namespace std;

	class Label {
	private:
		char m_frameArg[9]{};
		char* m_content;

	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label(); // this is the destructor

		istream& readLabel();
		ostream& printLabel()const;

		Label& text(const char* content);
	};
}

#endif