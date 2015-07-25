//
// Created by 越 on 2015/7/22.
//

#ifndef UMJI_VG101_PROJECT_FOR_GLOBALDEF_H
#define UMJI_VG101_PROJECT_FOR_GLOBALDEF_H

#include <list>
#include <iostream>

typedef int SectionIndex;
typedef int CourseIndex;
typedef int PersonnelID;
typedef int ClassNumber;

static const int LessonsPerDay=11;

typedef enum{
    Normal,
    Chem_Lab,
    Physics_Lab,
    Large_Hall,
    Medium_Hall,
    Music,
    room_type_count
}RoomType;

typedef enum {
    Sunday, Monday, Tuesday,
    Wednesday, Thursday, Friday,
    Saturday,
    day_count
}DayOfWeek;

typedef enum {
    Instructors,Students,
    person_count
} PersonnelType;

typedef enum{
    General,Mechanics, Computer_Science, Electronics,
    Physics, Mathematics, Pyschology, Social_Science,
    Literature, Chemistry, Material, Software_Engineering,
    Computer_Engineering,field_count
}Expertise;

typedef struct{
    DayOfWeek weekday;
    ClassNumber classnumber;
}ClassOfDay;

typedef struct{
    char building;
    int floor;
    int number;
}RoomName;


class Room {
public:
    std::string roomname;
    char building;
    int floor;
    int room_num;
    int capacity;
    RoomType rtype;
    Expertise exp;
private:
};

class Person {
public:
    std::string name;
    PersonnelID ID;
};

class Student:public Person {

};

class Teacher:public Person {
public:
    Expertise field;
private:

};

class Course{
    char* name;
    Expertise expertise;
    int section_num;
    char* course_code;
    int capacity;
    RoomType reqire_room;
};

class Section {
public:
    Section(SectionIndex,Course*);
    SectionIndex id;
    bool IsActive;
    int section_of_course;
    Teacher* teacher;
    Room* room;
    Course* course;
    std::list<Student*> student;
    std::list<ClassOfDay> schedule;
private:
};
#endif //UMJI_VG101_PROJECT_FOR_GLOBALDEF_H
