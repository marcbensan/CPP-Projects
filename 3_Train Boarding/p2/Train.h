/***********************************************************************
// Name: Denyl Marc Bensan
// StudentID: 171309222
// Course: OOP244
// Professor: Hong Huang
***********************************************************************/

#ifndef TRAIN_H
#define TRAIN_H

const int MIN_TIME = 700;
const int MAX_TIME = 2300;
const int MAX_NO_OF_PASSENGERS = 1000;

namespace sdds {
    class Train {
    private:
        char* name;
        int numOfPeople;
        int departureTime;

    public:

        void initialize();

        bool validTime(int value) const;

        bool validNoOfPassengers(int value) const;

        void set(const char* name);

        void set(int noOfPassengers, int departure);

        void set(const char* name, int noOfPassengers, int departure);

        void finalize();

        void display() const;

        bool isInvalid() const;

        int noOfPassengers() const;

        const char* getName() const;

        int getDepartureTime() const;

        bool load(int& passengers);

        bool updateDepartureTime();

        bool transfer(const Train& train);

        void deallocate(char* name);
    };
}
#endif