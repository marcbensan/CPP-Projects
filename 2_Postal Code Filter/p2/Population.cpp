/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*
Name: Denyl Marc Bensan
StudentID: 171309222
Course: OOP244
Professor: Hong Huang
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
namespace sdds {

    Populations* populations;
    int numOfMatches; // this will serve as the number for allocated memory size
    int sum; // this will accumulate the population sum

    void sort() {
        int i, j;
        Populations temp;
        for (i = numOfMatches - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populations[j].populationAmount > populations[j + 1].populationAmount) {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }

    bool startsWith(const char* cstring, const char* subString) 
    {
        return strstr(cstring, subString) == cstring;
    }

    bool getPostalCode(char* postal_code_prefix)
    {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> ";
        cin >> postal_code_prefix;   

        if (strcmp(postal_code_prefix, "!") == 0)
        {
            
            return false;
        }
        else
        {
            return true;
        }
    }

    bool load(const char* filename, const char* partial_postal_code_prefix)
    {
        bool ok = false;
        FILE* fptr = fopen("PCpopulationsComplete.csv", "r");

        bool isAll = (strcmp(partial_postal_code_prefix, "all") == 0);

        if (!openFile("PCpopulationsComplete.csv"))
        {
            cout << "Could not open file." << endl;
            return ok;
        }

        else if (isAll)
        {
            numOfMatches = noOfAll();
            populations = new Populations[numOfMatches];
            Populations tempPopulation;
            char line[100];

            if (populations != nullptr)
            {
                ok = true;

                for (int i = 0; i < numOfMatches; i++) 
                {                    
                    fgets(line, sizeof(line), fptr);
                    read(line, tempPopulation.postalCode);
                    read(line, tempPopulation.populationAmount);

                    populations[i] = tempPopulation;
                }

            }
        }

        else // THIS RUNS IF THE INPUT IS A PREFIX NOT "!" OR "all"
        {
            rewind(fptr);

            char line[100];
            Populations tempPopulation;

            numOfMatches = noOfMatches(partial_postal_code_prefix);
            populations = new Populations[numOfMatches];

            for (int i = 0; i < numOfMatches;) // to store the attributes of tempPopulation to the object array populations
            {
                fgets(line, sizeof(line), fptr);
                if (startsWith(line, partial_postal_code_prefix))
                {
                    read(line, tempPopulation.postalCode);
                    read(line, tempPopulation.populationAmount);
                    populations[i] = tempPopulation;
                    i++;
                }
            }
        }
        

        for (int i = 0; i < numOfMatches; i++) // to accumulate the population sum
        {
            sum += populations[i].populationAmount;
        }


        ok = true;
        closeFile();
        fclose(fptr);

        return ok;
    }

    void display(const Populations& population)
    {

        cout << population.postalCode << ":  " << population.populationAmount << endl;
    }

    void display()
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < numOfMatches; i++)
        {
            cout << i + 1 << "- ";
            display(populations[i]);

        }
        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << sum << "\n" << endl;
        sum = 0;

    }

    void deallocateMemory() {
        if (populations != nullptr) {
            for (int i = 0; i < numOfMatches; i++)
            {
                delete[] populations[i].postalCode;
            }
            delete[] populations;
            populations = nullptr;
        }

    }
}