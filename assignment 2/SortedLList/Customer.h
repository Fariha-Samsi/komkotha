#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

#include "PhoneNumber.h"
#include "Person.h"
#include "SortedLList.h"
#include "SortedLList.cpp"

using namespace std;

class Customer : public Person
{
    public:
        Customer();
        Customer(string);
        Customer(string, string, string, string, string, string,
            string, string, float, float, string, string, string, string);
        ~Customer();

        void addPhoneNumber(string phoneNumber);
        void removePhoneNumber(int);
        void removePhoneNumber(string);
        void changeOperator(string, PhoneNumber::Operator);
        void print();
        int getNumberOfPhoneNumbers();
        bool hasNoPhoneNumber();

        bool operator == (const string &) const;
        bool operator != (const string &) const;
        bool operator == (const Customer &) const;
        bool operator != (const Customer &) const;
        bool operator < (const Customer &) const;
        bool operator > (const Customer &) const;

    private:
        SortedLList<PhoneNumber> phoneNumbers;
};

#endif // CUSTOMER_H
