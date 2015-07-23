//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_PEOPLE_H
#define UMJI_VG101_PROJECT_FOR_PEOPLE_H
#include <iostream>
#include "globaldef.h"

class Person {
public:
    std::string getName();
    void setName(std::string& strname);
private:
    std::string name;
    PersonnelID ID;
    int type;
};

#endif //UMJI_VG101_PROJECT_FOR_PEOPLE_H
