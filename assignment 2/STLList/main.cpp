#include <iostream>

#include "PhoneNumber.h"
#include "Customer.h"
#include "CustomerDatabaseVector.h"

#define INITIAL_CAPACITY 2

using namespace std;

void runner_function()
{
    CustomerDatabaseVector database(INITIAL_CAPACITY);

    Customer fariha("Fariha", "Salam", "Maria", "Unmarried",
        "NID12345678", "", "Dhaka, Bangladesh.", "Rajshahi, Bangladesh",
        5.2, 45, "Black", "Black", "B+", "01712345677");
    database.add(&fariha);

    Customer maria("NID1234569");       // NID is mandatory to create user object...
    maria.setName("Maria");
    maria.setFathersName("Abbas");
    maria.setMothersName("Mumtaz");
    maria.setMaritalStatus("Unmarried");
    maria.setHeight(5.1);
    maria.setWeight(43);
    maria.setEyeColor("Brown");
    maria.setHairColor("Black");
    maria.setPresentAddress("Dhaka, Bangladesh");
    maria.setPermanentAddress("Noakhali, Bangladesh");
    maria.addPhoneNumber("01711354494");
    database.add(&maria);

    fariha.addPhoneNumber("01686480636");   // adding a new phone number Fariha's...

    // +1 users...
    Customer shafin("Shafin", "Haq", "Amina", "Unmarried",
        "NID12345670", "", "Dhaka, Bangladesh.", "Jessore, Bangladesh",
        5.6, 55, "Black", "Black", "AB+", "01712345672");
    database.add(&shafin);

    // 5 users...

    Customer tahsan("Tahsan", "Dewan", "Aklima", "Married",
        "NID12345671", "Farzana", "Dhaka, Bangladesh.", "Faridpur, Bangladesh",
        5.5, 57, "Black", "Black", "O-", "01972345673");
    database.add(&tahsan);

    Customer maruf("Maruf", "Hossain", "Kopila", "Unmarried",
        "NID12345672", "", "Dhaka, Bangladesh.", "Faridpur, Bangladesh",
        5.11, 65, "Black", "Black", "O+", "01812345674");
    database.add(&maruf);

    Customer sneha("Sneha", "Alamgir", "Shahnaj", "Unmarried",
        "NID12345673", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.3, 50, "Black", "Black", "B+", "01712345675");
    database.add(&sneha);

    Customer jahid("Jihad", "Jahangir", "Shirin", "Unmarried",
        "NID12345674", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.11, 77, "Black", "Black", "B+", "01712345676");
    database.add(&jahid);

    Customer prity("Prity", "Shahjahan", "Poly", "Unmarried",
        "NID12345675", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.2, 54, "Black", "Black", "AB+", "01212345677");
    database.add(&prity);

    cout << "INITIAL STATE OF DATABASE: " << endl << endl;

    database.printAll();

    cout << endl;

    fariha.addPhoneNumber("01216480638");
    fariha.addPhoneNumber("01226480639");
    fariha.addPhoneNumber("01936480640");
    fariha.addPhoneNumber("01246480632");
    fariha.addPhoneNumber("01556480650");

    shafin.changeOperator("01712345672", PhoneNumber::Banglalink);

    Customer *retrivedUser = database.get("Fariha");

    while ((*retrivedUser).getNumberOfPhoneNumbers() != 0)
    {
        (*retrivedUser).removePhoneNumber(0);
    }

    // fariha will be removed automatically...
    // database.remove("Fariha", "Tasnim");      // removing Fariha...

    Customer *retrivedUser_2 = database.get("Sneha");     // should return Sneha as the object is in index -> 0...
    (*retrivedUser_2).changeOperator("01712345675", PhoneNumber::KomKothaKoiben);     // operator is changed for Sneha's phone number...

    cout << "AFTER PERFORMING OPERATIONS ON DATABASE: " << endl << endl;

    database.printAll();
}

int main(int argc, const char **argv)
{
    runner_function();

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

    /*Customer customer("Fariha", "Salam", "Maria", "Unmarried",
        "NID12345678", "", "Dhaka, Bangladesh.", "Rajshahi, Bangladesh",
        5.2, 45, "Black", "Black", "B+", "01712345677");
    customer.addPhoneNumber("01816905001");
    customer.addPhoneNumber("01816905002");
    customer.addPhoneNumber("01816905003");
    customer.addPhoneNumber("01816905004");
    customer.addPhoneNumber("01816905005");
    customer.addPhoneNumber("01816905006");
    customer.addPhoneNumber("01816905007");
    customer.addPhoneNumber("01816905008");
    customer.addPhoneNumber("01816905009");
    customer.addPhoneNumber("01816905010");
    customer.addPhoneNumber("01816905011");
    customer.addPhoneNumber("01816905012");
    customer.addPhoneNumber("01816905013");
    customer.addPhoneNumber("01816905014");

    customer.changeOperator("01816905001", PhoneNumber::Banglalink);
    customer.print();*/

    return 0;
}
