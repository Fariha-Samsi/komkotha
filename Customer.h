#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <list>

#include "PhoneNumber.h"
#include "Person.h"

using namespace std;

class Customer : public Person
{
    public:
        Customer();
        Customer(string, string, string, string, string, string,
            string, string, float, float, string, string, string, string);
        ~Customer();

        void addPhoneNumber(string phoneNumber);
        void changeOperator(string, PhoneNumber::Operator);
        void print();

    private:
        list<PhoneNumber> phoneNumbers;
};

#endif // CUSTOMER_H
