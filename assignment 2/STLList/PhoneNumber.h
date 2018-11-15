#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include "Exception.h"

using namespace std;

class PhoneNumber
{
    public:
        enum Operator
        {
            Grameenphone,
            Robi,
            Banglalink,
            Teletalk,
            KomKothaKoiben
        };

        PhoneNumber(string);

        void changeOperator(Operator);
        string getOperatorCode();
        string getPhoneNumber();
        string getOperatorName();

        bool operator == (const string &) const;// { return name == s.name && id == s.id; }
        bool operator != (const string &) const;//  { return !operator==(s); }
        bool operator == (const PhoneNumber &) const;// { return name == s.name && id == s.id; }
        bool operator != (const PhoneNumber &) const;//  { return !operator==(s); }

    private:
        string phoneNumber;
        static string getOperatorName(int);
};

#endif // PHONENUMBER_H
