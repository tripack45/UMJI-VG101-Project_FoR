//
// Created by 越 on 2015/7/22.
//

#ifndef UMJI_VG101_PROJECT_FOR_GLOBALDEF_H
#define UMJI_VG101_PROJECT_FOR_GLOBALDEF_H

#include "Teacher.h"
#include "Room.h"

typedef int SessionIndex;
typedef int RoomIndex;
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

typedef struct{
    DayOfWeek weekday;
    ClassNumber classnumber;
}ClassOfDay;

typedef struct{
    char building;
    int floor;
    int number;
}RoomName;

#endif //UMJI_VG101_PROJECT_FOR_GLOBALDEF_H
