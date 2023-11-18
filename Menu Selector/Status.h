/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

using namespace std;
namespace sdds {

	class Status {
		char* m_desc;
		int m_code;

	public:
		Status(const char* desc = nullptr);
		Status(const Status& stat);
		Status& operator=(const char* desc);
		Status& operator=(int code);

		operator int() const;
		operator const char* () const;
		operator bool() const;

		Status& clear();

		ostream& print(ostream& ostr) const;
		~Status();

	};

	ostream& operator<<(ostream& os, const Status& status);
}
#endif 