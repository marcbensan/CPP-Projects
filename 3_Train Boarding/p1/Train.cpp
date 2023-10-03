/***********************************************************************
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Train.h"

using namespace std;
namespace sdds {

	Train trains;

	void Train::initialize() {
		name = nullptr;
		numOfPeople = -1;
		departureTime = -1;
	}

	bool Train::validTime(int value)const {
		bool isValidRange = (value >= MIN_TIME && value <= MAX_TIME);
		bool isValidMinute = (value % 100 < 60);

		if (isValidRange && isValidMinute) {
			return true;
		}

		return false;
	}

	bool Train::validNoOfPassengers(int value)const {
		bool isValid = (value > 0 && value <= MAX_NO_OF_PASSENGERS);

		if (isValid) {
			return true;
		}
		return false;
	}

	void Train::set(const char* trainName) {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}

		bool newName = trainName != nullptr && trainName[0] != '\0';

		if (newName) {
			name = new char[strlen(trainName) + 1];
			strcpy(name, trainName);
		}
	}

	void Train::set(int noOfPassengers, int departure) {

		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			numOfPeople = noOfPassengers;
			departureTime = departure;
		}
		else {
			numOfPeople = -1;
			departureTime = -1;
		}
	}

	void Train::set(const char* name, int noOfPassengers, int departure) {
		set(name);
		set(noOfPassengers, departure);
	}

	void Train::finalize() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
	}

	bool Train::isInvalid()const {
		bool emptyName = name == nullptr;
		bool invalidPeople = numOfPeople < 0;
		bool invalidTime = departureTime < 0;

		if (emptyName || invalidPeople || invalidTime) {
			return true;
		}
		return false;
	}

	int Train::noOfPassengers()const {
		return numOfPeople;
	}

	const char* Train::getName() const {
		return name;
	}

	int Train::getDepartureTime() const {
		return departureTime;
	}

	void Train::display()const {
		bool isValid = (name != nullptr && validNoOfPassengers(numOfPeople) && validTime(departureTime));
		if (isValid) {
			cout << "NAME OF THE TRAIN:    " << name << endl;
			cout << "NUMBER OF PASSENGERS: " << numOfPeople << endl;
			cout << "DEPARTURE TIME:       " << departureTime << endl;
		}
		else {
			cout << "Train in an invalid State!" << endl;
		}
	}

}