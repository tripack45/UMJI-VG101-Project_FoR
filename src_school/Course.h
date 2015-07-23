//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_COURSE_H
#define UMJI_VG101_PROJECT_FOR_COURSE_H
#include <iostream>
class Course {
public:
    std::string getName();
    void setName(std::string&);
    std::string getCourseCode();
    void setCourseCode(std::string&);
    int getCapacity();
    int getSessionNumber();
private:
    int capacity;
    int sessions;
    std::string name;
    std::string course_code;
};


#endif //UMJI_VG101_PROJECT_FOR_COURSE_H
