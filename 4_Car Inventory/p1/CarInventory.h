/**
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
**/

#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

#define YEAR_AND_CODE_SPACES 4
#define PRICE_SPACES 9
#define TYPE_SPACES 10
#define BRAND_AND_MODEL_SPACES 16

namespace sdds {
	class CarInventory {
	private:
		char* m_type{};
		char* m_brand{};
		char* m_model{};
		int m_year;
		int m_code;
		double m_price;

		void resetInfo();

	public:

		CarInventory();

		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);

		~CarInventory();//destructor

		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

		void printInfo() const;

		bool isValid() const;

		bool isSimilarTo(const CarInventory& car) const;
	};

	//global function
	int find_similar(CarInventory car[], const int num_cars);
}

#endif