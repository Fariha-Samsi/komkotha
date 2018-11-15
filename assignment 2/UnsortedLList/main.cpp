#include <iostream>

#include "PhoneNumber.h"
#include "Customer.h"
#include "Company.h"

using namespace std;

void runner_function()
{
    Company company;

    Customer fariha("Fariha", "Salam", "Maria", "Unmarried",
        "NID12345678", "", "Dhaka, Bangladesh.", "Rajshahi, Bangladesh",
        5.2, 45, "Black", "Black", "B+", "01712345677");
    company.add(&fariha);

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
    company.add(&maria);

    fariha.addPhoneNumber("01686480636");   // adding a new phone number Fariha's...

    // +1 users...
    Customer shafin("Shafin", "Haq", "Amina", "Unmarried",
        "NID12345670", "", "Dhaka, Bangladesh.", "Jessore, Bangladesh",
        5.6, 55, "Black", "Black", "AB+", "01712345672");
    company.add(&shafin);

    // 5 users...

    Customer tahsan("Tahsan", "Dewan", "Aklima", "Married",
        "NID12345671", "Farzana", "Dhaka, Bangladesh.", "Faridpur, Bangladesh",
        5.5, 57, "Black", "Black", "O-", "01972345673");
    company.add(&tahsan);

    Customer maruf("Maruf", "Hossain", "Kopila", "Unmarried",
        "NID12345672", "", "Dhaka, Bangladesh.", "Faridpur, Bangladesh",
        5.11, 65, "Black", "Black", "O+", "01812345674");
    company.add(&maruf);

    Customer sneha("Sneha", "Alamgir", "Shahnaj", "Unmarried",
        "NID12345673", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.3, 50, "Black", "Black", "B+", "01712345675");
    company.add(&sneha);

    Customer jahid("Jihad", "Jahangir", "Shirin", "Unmarried",
        "NID12345674", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.11, 77, "Black", "Black", "B+", "01712345676");
    company.add(&jahid);

    Customer prity("Prity", "Shahjahan", "Poly", "Unmarried",
        "NID12345675", "", "Dhaka, Bangladesh.", "Chandpur, Bangladesh",
        5.2, 54, "Black", "Black", "AB+", "01212345677");
    company.add(&prity);

    cout << "INITIAL STATE OF DATABASE: " << endl << endl;

    company.printAll();

    cout << endl;

    fariha.addPhoneNumber("01216480638");
    fariha.addPhoneNumber("01226480639");
    fariha.addPhoneNumber("01936480640");
    fariha.addPhoneNumber("01246480632");
    fariha.addPhoneNumber("01556480650");

    shafin.changeOperator("01712345672", PhoneNumber::Banglalink);

    Customer *retrivedUser = company.get("Fariha");

    while ((*retrivedUser).getNumberOfPhoneNumbers() != 0)
    {
        (*retrivedUser).removePhoneNumber(0);
    }

    // fariha will be removed automatically...
    // company.remove("Fariha", "Tasnim");      // removing Fariha...

    Customer *retrivedUser_2 = company.get("Sneha");     // should return Sneha as the object is in index -> 0...
    (*retrivedUser_2).changeOperator("01712345675", PhoneNumber::KomKothaKoiben);     // operator is changed for Sneha's phone number...

    cout << "AFTER PERFORMING OPERATIONS ON DATABASE: " << endl << endl;

    company.printAll();
}

int main()
{
    runner_function();

    return 0;
}
