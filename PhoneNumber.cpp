#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(string phoneNumber)
{
    if (phoneNumber.length() != 11)
    {
        throw Exception("Invalid phone number.");
    }

    operatorCode = phoneNumber.substr(0, phoneNumber.length() - 8);
    number = phoneNumber.substr(3);
}

void PhoneNumber::changeOperator(Operator newOperator)
{
    int lastDigit;

    switch (newOperator)
    {
        case Operator::Grameenphone:
            lastDigit = '7';

            break;
        case Operator::Robi:
            lastDigit = '8';

            break;
        case Operator::Banglalink:
            lastDigit = '9';

            break;
        case Operator::Teletalk:
            lastDigit = '5';

            break;
        case Operator::KomKothaKoiben:
            lastDigit = '2';

            break;
    };

    operatorCode[operatorCode.length() - 1] = lastDigit;
}

string PhoneNumber::getOperatorCode()
{
    return operatorCode;
}

string PhoneNumber::getOperatorName()
{
    int index = 0;

    switch (operatorCode[operatorCode.length() - 1])
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

string PhoneNumber::getNumber()
{
    return number;
}

string PhoneNumber::toString()
{
    return operatorCode + number;
}

bool PhoneNumber::operator == (string &phoneNumber) const
{
    if (toString() == phoneNumber)
    {
        return true;
    }

    return false;
}

bool PhoneNumber::operator != (string &phoneNumber) const
{
    return !(operator == (phoneNumber));
}

bool PhoneNumber::operator == (PhoneNumber &phoneNumber) const
{
    if (toString() == phoneNumber.toString())
    {
        return true;
    }

    return false;
}

bool PhoneNumber::operator != (PhoneNumber &phoneNumber) const
{
    return !(operator == (phoneNumber));
}
