#ifndef CUSTOMERDATABASEVECTOR_H
#define CUSTOMERDATABASEVECTOR_H

#include <iostream>
#include <vector>

#include "Customer.h"

using namespace std;

class CustomerDatabaseVector
{
    public:
        CustomerDatabaseVector(int);
        ~CustomerDatabaseVector();

        void add(Customer *);
        void printAll();
        Customer * get(int);
        Customer * get(string);
        void remove(int);
        void remove(string);

    private:
        vector<Customer *> customers;

        void revalidate();
};

#endif // CUSTOMERDATABASEVECTOR_H
