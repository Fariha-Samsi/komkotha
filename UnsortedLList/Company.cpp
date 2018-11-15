#include "Company.h"

Company::Company()
{

}

Company::~Company()
{
    customers.clear();
}

void Company::add(Customer *customer)
{
    customers.add(customer);
    revalidate();
}

Customer * Company::get(int index)
{
    revalidate();

    if ((unsigned int)index >= customers.getLength())
    {
        cout << "error: index greater than or equal to size of the vector." << endl;

        return (Customer *)0;
    }

    int i = 0;

    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();

        if (i == index)
        {
            return customer;
        }
    }

    return (Customer *)0;
}

Customer * Company::get(string name)
{
    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();

        if (name == (*customer).getName())
        {
            return customer;
        }
    }

    return (Customer *)0;
}

void Company::remove(int index)
{
    revalidate();

    if ((unsigned int)index >= customers.getLength())
    {
        cout << "error: index greater than or equal to size of the vector." << endl;

        return;
    }

    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();
        customers.remove(*customer);
    }
}

void Company::remove(string name)
{
    revalidate();

    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();

        if (name == (*customer).getName())
        {
            customers.remove(*customer);

            break;
        }
    }
}

void Company::revalidate()
{
    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();

        if ((*customer).getNumberOfPhoneNumbers() == 0)
        {
            customers.remove(*customer);
        }
    }
}

void Company::printAll()
{
    revalidate();

    customers.reset();

    while (customers.hasNext())
    {
        Customer *customer = customers.nextElement();
        customer->print();

        cout << endl;
    }

    /*phoneNumbers.reset();

    while (phoneNumbers.hasNext())
    {
        PhoneNumber *phoneNumber = phoneNumbers.nextElement();

        cout << (*phoneNumber).getPhoneNumber() << " - " << (*phoneNumber).getOperatorName() <<  ", ";
    }*/
}
