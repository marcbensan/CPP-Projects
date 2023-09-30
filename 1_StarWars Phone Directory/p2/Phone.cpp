#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include "cStrTools.h"
#include <iostream>
#include <cstdio>  // Include for fscanf
using namespace std;

namespace sdds {
    void phoneDir(const char* programTitle, const char* fileName) {

        char name[51];
        char areaCode[4];
        char prefix[4];
        char number[5];
        char shortName[51];

        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");
        if (!file) {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        while (true) {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin.getline(shortName, sizeof(shortName));

            if (shortName[0] == '!') {
                break;
            }

            bool found = false;

            while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) == 4) {

                char lowerName[51];
                char lowerShortName[51];
                toLowerCaseAndCopy(lowerName, name);
                toLowerCaseAndCopy(lowerShortName, shortName);

                if (strStr(lowerName, lowerShortName) != nullptr) {
                    cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
                    found = true;
                }
            }

            rewind(file);

            if (!found) {
            }
        }

        fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}
