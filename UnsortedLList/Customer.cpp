#include "Customer.h"

Customer::Customer() : Person()
{

}

Customer::Customer(string nationalID) : Person(nationalID)
{

}

Customer::Customer(string name, string fathersName, string mothersName,
            string maritalStatus, string nationalID, string spousesName,
            string presentAddress, string permanentAddress,
            float height, float weight, string eyeColor, string hairColor,
            string bloodGroup, string phoneNumber) : Person(name, fathersName, mothersName,
            maritalStatus, nationalID, spousesName, presentAddress,
            permanentAddress, height, weight, eyeColor, hairColor, bloodGroup)
{
    addPhoneNumber(phoneNumber);        // try catch not needed as this is going to be the first phone number...
}

Customer::~Customer()
{
    if (phoneNumbers.getLength() > 0)
    {
        phoneNumbers.clear();
    }
}

void Customer::addPhoneNumber(string newPhoneNumber)
{
    if (phoneNumbers.getLength() < 15)
    {
        phoneNumbers.reset();

        while (phoneNumbers.hasNext())
        {
            if (*(phoneNumbers.nextElement()) == newPhoneNumber)
            {
                cout << "The phone number that you are trying to add already exists in your database. Please try another number." << endl;

                return;
            }
        }

        phoneNumbers.add(new PhoneNumber(newPhoneNumber));
    }
    else
    {
        cout << "Exceeded maximum limit of phone numbers." << endl;

        return;
    }
}

void Customer::removePhoneNumber(int index)
{
    if (index < 0 || (unsigned int)index >= phoneNumbers.getLength())
    {
        cout << "error: invalid index." << endl;

        return;
    }

    int iterator = 0;

    phoneNumbers.reset();

    while (phoneNumbers.hasNext())
    {
        if (iterator == index)
        {
            phoneNumbers.remove(*phoneNumbers.nextElement());

            break;
        }

        phoneNumbers.nextElement();
    }
}

void Customer::removePhoneNumber(string phoneNumberToRemove)
{
    phoneNumbers.reset();

    while (phoneNumbers.hasNext())
    {
        PhoneNumber *phoneNumber = phoneNumbers.nextElement();

        if (*phoneNumber == phoneNumberToRemove)
        {
            phoneNumbers.remove(*phoneNumber);

            return;
        }
    }
}

void Customer::changeOperator(string phoneNumberToChangeOperator, PhoneNumber::Operator newOperator)
{
    phoneNumbers.reset();

    while (phoneNumbers.hasNext())
    {
        PhoneNumber *phoneNumber = phoneNumbers.nextElement();

        if (*phoneNumber == phoneNumberToChangeOperator)
        {
            phoneNumbers.remove(*phoneNumber);
            (*phoneNumber).changeOperator(newOperator);
            addPhoneNumber((*phoneNumber).getPhoneNumber());

            return;
        }
    }
}

int Customer::getNumberOfPhoneNumbers()
{
    return phoneNumbers.getLength();
}

void Customer::print()
{
    Person::print();

    cout << "Phone number(s): ";

    phoneNumbers.reset();

    while (phoneNumbers.hasNext())
    {
        PhoneNumber *phoneNumber = phoneNumbers.nextElement();

        cout << (*phoneNumber).getPhoneNumber() << " - " << (*phoneNumber).getOperatorName() <<  ", ";
    }

    cout << endl;
}

bool Customer::operator == (const string &name) const
{
    if (this->name == name)
    {
        return true;
    }

    return false;
}

bool Customer::operator != (const string &name) const
{
    return !(operator == (name));
}

bool Customer::operator == (const Customer &customer) const
{
    if (this->name == customer.name)
    {
        return true;
    }

    return false;
}

bool Customer::operator != (const Customer &customer) const
{
    return !(operator == (customer));
}
