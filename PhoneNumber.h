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

        void changeOperator(Operator newoOperator);
        string getOperatorName();
        string getOperatorCode();
        string getNumber();
        string toString();

        bool operator == (string &) const;// { return name == s.name && id == s.id; }
        bool operator != (string &) const;//  { return !operator==(s); }
        bool operator == (PhoneNumber &) const;// { return name == s.name && id == s.id; }
        bool operator != (PhoneNumber &) const;//  { return !operator==(s); }

    private:
        string operatorCode, number;
        static string getOperatorName(int);
};

#endif // PHONENUMBER_H
