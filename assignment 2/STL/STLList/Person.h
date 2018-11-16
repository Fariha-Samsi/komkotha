#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "Exception.h"

using namespace std;

class Person
{
    public:
        Person();
        Person(string);
        Person(string, string, string, string, string, string,
            string, string, float, float, string, string, string);

        float getHeight();
        float getWeight();

        string getName();
        string getFathersName();
        string getMothersName();
        string getMaritalStatus();
        string getNationalID();
        string getSpousesName();
        string getPresentAddress();
        string getPermanentAddress();
        string getEyeColor();
        string getHairColor();
        string getBloodGroup();

        void setHeight(float);
        void setWeight(float);

        void setName(string);
        void setFathersName(string);
        void setMothersName(string);
        void setMaritalStatus(string);
        void setNationalID(string);
        void setSpousesName(string);
        void setPresentAddress(string);
        void setPermanentAddress(string);
        void setEyeColor(string);
        void setHairColor(string);
        void setBloodGroup(string);

        void print();

    private:
        float height, weight;

        string name, fathersName, mothersName,
            maritalStatus, nationalID, spousesName, presentAddress,
            permanentAddress, eyeColor, hairColor, bloodGroup;
};

#endif // PERSON_H
