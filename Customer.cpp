#include "Customer.h"

Customer::Customer() : Person()
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
    if (phoneNumbers.size() > 0)
    {
        phoneNumbers.clear();
    }
}

void Customer::addPhoneNumber(string phoneNumber)
{
    if (phoneNumbers.size() < 15)
    {
        phoneNumbers.insert(phoneNumbers.end(), PhoneNumber(phoneNumber));
    }
    else
    {
        throw Exception("Exceeded maximum limit of phone numbers.");
    }
}

void Customer::changeOperator(string phoneNumberToChangeOperator, PhoneNumber::Operator newOperator)
{
    for (PhoneNumber phoneNumber : phoneNumbers)
    {
        if (phoneNumber == phoneNumberToChangeOperator)
        {
            cout << "EQUAL" << endl;
            // phoneNumbers.remove(phoneNumber);
            // phoneNumber.changeOperator(newOperator);

            break;
        }
        else if (phoneNumber != phoneNumberToChangeOperator)
        {
            cout << "NOT EQUAL" << endl;
        }
    }
}

void Customer::print()
{
    Person::print();

    cout << "Phone number(s): ";

    for (PhoneNumber phoneNumber : phoneNumbers)
    {
        cout << phoneNumber.toString() << ", ";
    }

    cout << endl;
}
