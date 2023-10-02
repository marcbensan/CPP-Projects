/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

/*
Name: Denyl Marc Bensan
StudentID: 171309222
Course: OOP
Prof: Hong Huang
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument

    bool load(FILE* fptr, Employee& employee)
    {
        bool ok = false;

        if (read(fptr, employee.m_empNo) && read(fptr, employee.m_salary) && read(fptr, employee.m_name))
        {
            ok = true;
        }

        else
        {
            ok = false;
        }
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 

    bool load()
    {
        bool ok = false;
        FILE* file = fopen("employees.csv", "r");

        if (openFile("employees.csv"))
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];

            if (employees != nullptr)
            {
                ok = true;

                for (int i = 0; i < noOfEmployees; i++)
                {
                    Employee tempEmployee;

                    if (!load(file, tempEmployee))
                    {
                        ok = false;
                        break;
                    }
                    employees[i] = tempEmployee;
                }
            }
            closeFile();
            fclose(file);
        }
        else
        {
            cout << "Could not open data file: " << file << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& employee)
    {
        cout << employee.m_empNo << ": " << employee.m_name << ", $" << (int)employee.m_salary << endl; //casting because the output salary has no decimal.
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory() {
        if (employees != nullptr) {
            for (int i = 0; i < noOfEmployees; i++)
            {
                delete[] employees[i].m_name;
            }
            delete[] employees;
            employees = nullptr;
        }
    }
}
