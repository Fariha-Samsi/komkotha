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
    if (getNumberOfPhoneNumbers() > 0)
    {
        phoneNumbers.clear();
    }
}

void Customer::addPhoneNumber(string newPhoneNumber)
{
    if (getNumberOfPhoneNumbers() < 15)
    {
        for (PhoneNumber phoneNumber : phoneNumbers)
        {
            if (phoneNumber == newPhoneNumber)
            {
                cout << "The phone number that you are trying to add already exists in your database. Please try another number." << endl;

                return;
            }
        }

        phoneNumbers.push_front(PhoneNumber(newPhoneNumber));
    }
    else
    {
        cout << "Exceeded maximum limit of phone numbers." << endl;

        return;
    }
}

void Customer::removePhoneNumber(int index)
{
    if (index < 0 || index >= getNumberOfPhoneNumbers())
    {
        printf("error: invalid index.\n");

        return;
    }

    forward_list<PhoneNumber>::iterator phoneNumbersIterator = phoneNumbers.begin();
    advance(phoneNumbersIterator, index);
    phoneNumbers.remove(*phoneNumbersIterator);
}

void Customer::removePhoneNumber(string phoneNumberToRemove)
{
    for (PhoneNumber phoneNumber : phoneNumbers)
    {
        if (phoneNumber == phoneNumberToRemove)
        {
            phoneNumbers.remove(phoneNumber);

            return;
        }
    }
}

void Customer::changeOperator(string phoneNumberToChangeOperator, PhoneNumber::Operator newOperator)
{
    for (PhoneNumber phoneNumber : phoneNumbers)
    {
        if (phoneNumber == phoneNumberToChangeOperator)
        {
            phoneNumbers.remove(phoneNumber);
            phoneNumber.changeOperator(newOperator);
            addPhoneNumber(phoneNumber.getPhoneNumber());

            return;
        }
    }
}

int Customer::getNumberOfPhoneNumbers()
{
    int numberOfPhoneNumbers = 0;
    forward_list<PhoneNumber>::const_iterator phoneNumberIterator;

    for (phoneNumberIterator = phoneNumbers.begin(); phoneNumberIterator != phoneNumbers.end(); phoneNumberIterator++)
    {
        numberOfPhoneNumbers++;
    }

    return numberOfPhoneNumbers;
}

void Customer::print()
{
    Person::print();

    cout << "Phone number(s): ";

    for (PhoneNumber phoneNumber : phoneNumbers)
    {
        cout << phoneNumber.getPhoneNumber() << " - " << phoneNumber.getOperatorName() <<  ", ";
    }

    cout << endl;
}
