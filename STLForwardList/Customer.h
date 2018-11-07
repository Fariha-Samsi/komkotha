#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <forward_list>

#include "PhoneNumber.h"
#include "Person.h"

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

    private:
        forward_list<PhoneNumber> phoneNumbers;
};

#endif // CUSTOMER_H
