//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_COLLEGE_H
#define UMJI_VG101_PROJECT_FOR_COLLEGE_H

#include <iostream>
#include <vector>
#include <list>
#include "globaldef.h"
#include "Database.h"

class College {
public:
    std::string getName();
    void setName(std::string& strname);
    //===========Resourses Management========
    void AddRoom   (char building_,
                    int floor_,
                    int room_num_,
                    int capacity_,
                    RoomType rtype_=Normal,
                    Expertise exp_=General
                    );
    void AddTeacher (std::string& name,
                     Expertise exp
                    );
    void AddStudent (std::string& name
                    );
    void AddCourse (char* name_,
                    Expertise expertise_,
                    int section_num_,
                    char* course_code_=NULL,
                    int capacity_=15,
                    RoomType reqire_room_=Normal
                    );
    //======================================


    void ListFaculty();
    void ListStudent();
    void ListCourses();

private:
    Section* getSectionPtr(SectionIndex);
    Person* getPersonPtr(PersonnelID);
    Room* getRoomPtr(RoomName);

    std::string name;

    DataEntries<Teacher> teacher;
    DataEntries<Student> student;
    DataEntries<Course> course;
    DataEntries<Section> section;

PersonnelID GeneratePersonnelID();
CourseIndex GenerateCourseIndex();
SectionIndex GenerateSectionID();
};


#endif //UMJI_VG101_PROJECT_FOR_COLLEGE_H
