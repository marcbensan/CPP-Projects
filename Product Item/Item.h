#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include "Status.h"
#include "iProduct.h"

using namespace std;

namespace sdds {
	class Item : public iProduct{
		double m_price;
		int m_quantity;
		int m_neededQty;
		char* m_desc;
		bool m_Linear;
		
	protected:
		Status m_status;
		int m_sku;
		bool linear()const;

	public:
		Item();
		Item(const Item& other);
		Item& operator=(const Item& other);
		~Item();

		// query overrides
		int qtyNeeded() const;
		int qty() const;
		operator double() const;
		operator bool() const;

		// modifier overrides
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);

		void clear();

		// operator== overrides
		bool operator==(int sku) const;
		bool operator==(const char* description) const;

		// I/O overrides
		ofstream& save(ofstream& ofstr) const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr) const;
		istream& read(istream& istr);
		int readSku(istream& istr);
	};
}
#endif