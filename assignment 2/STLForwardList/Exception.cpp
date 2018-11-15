#include "Exception.h"

Exception::Exception(string message) : exception()
{
    this->message = message;
}

const char * Exception::what() const throw()
{
    return message.c_str();
}
