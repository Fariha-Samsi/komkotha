#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>

#include "Customer.h"

using namespace std;

class Company
{
    public:
        Company();
        ~Company();

        void add(Customer *);
        void printAll();
        Customer * get(int);
        Customer * get(string);
        void remove(int);
        void remove(string);

    private:
        UnsortedLList<Customer> customers;

        void revalidate();
};

#endif // COMPANY_H
