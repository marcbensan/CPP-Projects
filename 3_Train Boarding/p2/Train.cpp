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
#include <string>
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

	bool Train::load(int& passengers) {

		cout << "Enter number of passengers boarding:" << endl;
		cout << "> ";
		cin >> passengers;

		numOfPeople += passengers;

		int unboardedPassengers = numOfPeople % MAX_NO_OF_PASSENGERS;

		if (numOfPeople < MAX_NO_OF_PASSENGERS) {
			return true;
		}
		else {
			passengers = unboardedPassengers;
			return false;
		}

	}

	bool Train::updateDepartureTime() {
		int newDepartureTime;
		cout << "Enter new departure time:" << endl;
		cout << "> ";
		cin >> newDepartureTime;

		if (validTime(newDepartureTime)) {
			departureTime = newDepartureTime;
			return true;
		}
		else {
			departureTime = -1;
			return false;
		}
	}

	bool Train::transfer(const Train& otherTrain) {
		bool invalidState = (isInvalid() || otherTrain.isInvalid());
		bool isFull = (numOfPeople + otherTrain.numOfPeople > MAX_NO_OF_PASSENGERS);

		if (invalidState) {
			return false;
			
		}

		int totalLength = strlen(this->name) + strlen(otherTrain.name) + 3;

		// Dynamically allocate memory for the combined name
		char* combinename = new char[totalLength];

		// Combine the names of this train and the other train
		strcpy(combinename, this->name);
		strcat(combinename, ", ");
		strcat(combinename, otherTrain.name);

		// Delete the existing name of this train and assign the combined name
		delete[] this->name;
		this->name = combinename;

		numOfPeople += otherTrain.numOfPeople;

		if (isFull) {
			int unboardedPassengers = numOfPeople % MAX_NO_OF_PASSENGERS;
			cout << "Train is full; " << unboardedPassengers << " passengers of " << otherTrain.name << " could not be boarded!" << endl;
			numOfPeople -= unboardedPassengers;

		}

		return true;

	}

}