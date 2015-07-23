//
// Created by 越 on 2015/7/21.
//

#include "Course.h"

std::string Course::getCourseCode() {
    return course_code;
}

void Course::setCourseCode(int i) {
    course_code=i;
}

std::string Course::getName() {
    return name;
}

void Course::setName(std::string &strname) {
    name=strname;
    return;
}