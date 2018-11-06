#include "Person.h"

Person::Person()
{
    height = weight = 0.0f;
    name = fathersName = mothersName =
        maritalStatus = nationalID = spousesName = presentAddress =
        permanentAddress = eyeColor = hairColor = bloodGroup = "None";
}

Person::Person(string name, string fathersName, string mothersName,
                string maritalStatus, string nationalID, string spousesName,
                string presentAddress, string permanentAddress,
                float height, float weight, string eyeColor, string hairColor,
                string bloodGroup)
{
    setName(name);
    setFathersName(fathersName);
    setMothersName(mothersName);
    setMaritalStatus(maritalStatus);
    setNationalID(nationalID);

    if (maritalStatus == "Married")
    {
        setSpousesName(spousesName);
    }
    else
    {
        setSpousesName("None");
    }

    setPresentAddress(presentAddress);
    setPermanentAddress(permanentAddress);
    setHeight(height);
    setWeight(weight);
    setEyeColor(eyeColor);
    setHairColor(hairColor);
    setBloodGroup(bloodGroup);
}

float Person::getHeight()
{
    return height;
}

void Person::setHeight(float height)
{
    this->height = height;
}

float Person::getWeight()
{
    return weight;
}

void Person::setWeight(float weight)
{
    this->weight = weight;
}

string Person::getName()
{
    return name;
}

string Person::getFathersName()
{
    return fathersName;
}

string Person::getMothersName()
{
    return mothersName;
}

string Person::getMaritalStatus()
{
    return maritalStatus;
}

string Person::getNationalID()
{
    return nationalID;
}

string Person::getSpousesName()
{
    return spousesName;
}

string Person::getPresentAddress()
{
    return presentAddress;
}

string Person::getPermanentAddress()
{
    return permanentAddress;
}

string Person::getEyeColor()
{
    return eyeColor;
}

string Person::getHairColor()
{
    return hairColor;
}

string Person::getBloodGroup()
{
    return bloodGroup;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setFathersName(string fathersName)
{
    this->fathersName = fathersName;
}

void Person::setMothersName(string mothersName)
{
    this->mothersName = mothersName;
}

void Person::setMaritalStatus(string maritalStatus)
{
    this->maritalStatus = maritalStatus;
}

void Person::setNationalID(string nationalID)
{
    if (nationalID.length() != 11)
    {
        throw Exception("Invalid national id.");
    }

    this->nationalID = nationalID;
}

void Person::setSpousesName(string spousesName)
{
    this->spousesName = spousesName;
}

void Person::setPresentAddress(string presentAddress)
{
    this->presentAddress = presentAddress;
}

void Person::setPermanentAddress(string permanentAddress)
{
    this->permanentAddress = permanentAddress;
}

void Person::setEyeColor(string eyeColor)
{
    this->eyeColor = eyeColor;
}

void Person::setHairColor(string hairColor)
{
    this->hairColor = hairColor;
}

void Person::setBloodGroup(string bloodGroup)
{
    this->bloodGroup = bloodGroup;
}

void Person::print()
{
    cout << "Name: " << name << endl <<
            "Father's name: " << fathersName << endl <<
            "Mother's name: " << mothersName << endl <<
            "Marital status: " << maritalStatus << endl;

    if (maritalStatus == "Married")
    {
        cout << "Spouse's name: " << spousesName << endl;
    }

    cout << "National ID: " << nationalID << endl <<
            "Present address: " << presentAddress << endl <<
            "Permanent address: " << permanentAddress << endl <<
            "Height: " << height << " feet" << endl <<
            "Weight: " << weight << " kg" << endl <<
            "Eye's color: " << eyeColor << endl <<
            "Hair color: " << hairColor << endl <<
            "Blood group: " << bloodGroup << endl;
}
