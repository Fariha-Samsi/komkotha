#include "Exception.h"

Exception::Exception(string message) : exception()
{
    this->message = message;
}

Exception::~Exception() throw()
{

}

const char * Exception::what() const throw()
{
    return message.c_str();
}
