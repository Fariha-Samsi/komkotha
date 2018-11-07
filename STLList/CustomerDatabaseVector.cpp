#include "CustomerDatabaseVector.h"

// vector will re-allocate each time incrementing size by initial size...
CustomerDatabaseVector::CustomerDatabaseVector(int initialSize)
{
    customers.reserve(initialSize);
}

CustomerDatabaseVector::~CustomerDatabaseVector()
{
    customers.clear();
}

void CustomerDatabaseVector::add(Customer *customer)
{
    revalidate();
    customers.push_back(customer);
}

Customer * CustomerDatabaseVector::get(int index)
{
    revalidate();

    if ((size_t)index >= customers.size())
    {
        printf("error: index greater than or equal to size of the vector.\n");

        return (Customer *)0;
    }

    return customers[index];
}

Customer * CustomerDatabaseVector::get(string name)
{
    size_t customersLength = customers.size();

    for (size_t index = 0; index < customersLength; index++)
    {
        Customer *customer = customers[index];

        if (name == (*customer).getName())
        {
            return customers[index];
        }
    }

    return (Customer *)0;
}

void CustomerDatabaseVector::remove(int index)
{
    revalidate();

    if ((size_t)index >= customers.size())
    {
        printf("error: index greater than or equal to size of the vector.\n");

        return;
    }

    customers.erase(customers.begin() + index);
}

void CustomerDatabaseVector::remove(string name)
{
    revalidate();

    size_t customersLength = customers.size();

    for (size_t index = 0; index < customersLength; index++)
    {
        Customer *customer = customers[index];

        if (name == (*customer).getName())
        {
            customers.erase(customers.begin() + index);
        }
    }
}

void CustomerDatabaseVector::revalidate()
{
    size_t customersLength = customers.size();

    for (size_t index = 0; index < customersLength; index++)
    {
        Customer *customer = customers[index];

        if ((*customer).getNumberOfPhoneNumbers() == 0)
        {
            customers.erase(customers.begin() + index);
        }
    }
}

void CustomerDatabaseVector::printAll()
{
    revalidate();

    size_t customersLength = customers.size();

    for (size_t index = 0; index < customersLength; index++)
    {
        (*customers[index]).print();

        cout << endl;
    }
}
