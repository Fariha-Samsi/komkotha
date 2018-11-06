#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

class Exception : public exception
{
    public:
        Exception(string);
        virtual const char * what() const throw();

    private:
        string message;
};

#endif // EXCEPTION_H
