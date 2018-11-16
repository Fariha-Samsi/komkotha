#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(string phoneNumber)
{
    if (phoneNumber.length() != 11)
    {
        throw Exception("Invalid phone number.");
    }

    this->phoneNumber = phoneNumber;
    // operatorCode = phoneNumber.substr(0, phoneNumber.length() - 8);
    // number = phoneNumber.substr(3);
}

void PhoneNumber::changeOperator(Operator newOperator)
{
    int lastDigit;

    switch (newOperator)
    {
        case Grameenphone:
            lastDigit = '7';

            break;
        case Robi:
            lastDigit = '8';

            break;
        case Banglalink:
            lastDigit = '9';

            break;
        case Teletalk:
            lastDigit = '5';

            break;
        case KomKothaKoiben:
            lastDigit = '2';

            break;
    };

    phoneNumber[2] = lastDigit;
}

string PhoneNumber::getOperatorCode()
{
    return phoneNumber.substr(0, phoneNumber.length() - 8);
}

string PhoneNumber::getPhoneNumber()
{
    return phoneNumber;
}

string PhoneNumber::getOperatorName()
{
    int index = 0;

    switch (phoneNumber[2])
    {
        case '7':
            index = 0;

            break;
        case '8':
            index = 1;

            break;
        case '9':
            index = 2;

            break;
        case '5':
            index = 3;

            break;
        default:
            index = 4;
    };

    return getOperatorName(index);
}

string PhoneNumber::getOperatorName(int index)
{
    static const string operatorNames[5] = {
        "Grameenphone", "Robi", "Banglalink",
        "Teletalk", "KomKothaKoiben"
    };

    return operatorNames[index];
}

bool PhoneNumber::operator == (const string &phoneNumber) const
{
    if (this->phoneNumber == phoneNumber)
    {
        return true;
    }

    return false;
}

bool PhoneNumber::operator != (const string &phoneNumber) const
{
    return !(operator == (phoneNumber));
}

bool PhoneNumber::operator == (const PhoneNumber &phoneNumber) const
{
    if (this->phoneNumber == phoneNumber.phoneNumber)
    {
        return true;
    }

    return false;
}

bool PhoneNumber::operator != (const PhoneNumber &phoneNumber) const
{
    return !(operator == (phoneNumber));
}
