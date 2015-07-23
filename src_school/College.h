//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_COLLEGE_H
#define UMJI_VG101_PROJECT_FOR_COLLEGE_H

#include <iostream>
#include <vector>
#include <list>
#include "globaldef.h"
#include "Building.h"
#include "Session.h"
#include "Schedule.h"
#include "Teacher.h"

class College {
public:
    std::string getName();
    void setName(std::string& strname);
    void AddBuilding(Building*);
    void AddFaculty(Teacher*);
    void AddCourse(Course*);

    Session getCourseArrangements(CourseIndex);
    Schedule getSessionArrangement(SessionIndex);
    Schedule getFacultySchedule(PersonnelID);
    Schedule getStudentSchedule(PersonnelID);

    void ListFaculty();
    void ListStudent();
    void ListCourses();

private:
    typedef struct{
        Course* course;
        CourseIndex index;
    }CourseReg;
    typedef struct{
        Person* person;
        PersonnelID id;
    }PersonnelReg;
    std::string name;
    std::list<Building*> building;
    std::list<CourseReg*> course;
    std::list<PersonnelReg*> teacher;
    std::list<PersonnelReg*> student;
    std::list<Session*> session;
};


#endif //UMJI_VG101_PROJECT_FOR_COLLEGE_H
