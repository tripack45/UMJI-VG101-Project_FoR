//
// Created by 越 on 2015/7/22.
//

#ifndef UMJI_VG101_PROJECT_FOR_SESSION_H
#define UMJI_VG101_PROJECT_FOR_SESSION_H


#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include <list>

class Session {
public:
    Session(SessionIndex);
    SessionIndex id;
    int session_of_course;
    Teacher* teacher;
    Room* room;
    Course* course;
    std::list<Student*> student;
    std::list<ClassOfDay> schedule;
private:
};


#endif //UMJI_VG101_PROJECT_FOR_SESSION_H
