/**
// Name: Denyl Marc Bensan
// email: mbensan@myseneca.ca
// Date: 2023-11-02
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/


#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>

using namespace std;
namespace sdds {
    const int MaxNameLength = 55;
    class HealthCard {
        char* m_name{};
        long long m_number;
        char m_vCode[3];
        char m_sNumber[10];

        // Private methods
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(istream& istr, char ch) const;
        ostream& printIDInfo(ostream& ostr)const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

    public:
        HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
        HealthCard(const HealthCard& hc);
        HealthCard& operator=(const HealthCard& hc);
        ~HealthCard();
        operator bool() const;
        ostream& print(ostream& ostr, bool toFile = true) const;
        istream& read(istream& istr);
    };
    ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
    istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H