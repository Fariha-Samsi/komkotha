#include <iostream>

#include "PhoneNumber.h"
#include "Customer.h"

using namespace std;

int main(int argc, const char **argv)
{
    /*try
    {
        PhoneNumber phoneNumber("01511354495");

        cout << "Phone number: " << phoneNumber.toString() << endl;
        cout << "Operator code: " << phoneNumber.getOperatorCode() << endl;
        cout << "Operator name: " << phoneNumber.getOperatorName() << endl << endl;

        phoneNumber.changeOperator(PhoneNumber::Banglalink);

        cout << "New phone number: " << phoneNumber.toString() << endl;
        cout << "New operator code: " << phoneNumber.getOperatorCode() << endl;
        cout << "New operator name: " << phoneNumber.getOperatorName() << endl << endl;
    }
    catch (PhoneNumberException &phoneNumberException)
    {
        cout << phoneNumberException.what() << endl;
    }*/

    Customer customer("Fariha", "Salam", "Maria", "Unmarried",
        "NID12345678", "Shafin", "Dhaka, Bangladesh.", "Rajshahi, Bangladesh",
        5.2, 45, "Black", "Black", "B+", "01712345677");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905001");

    customer.changeOperator("01816905001", PhoneNumber::Banglalink);
    customer.print();

    return 0;
}
