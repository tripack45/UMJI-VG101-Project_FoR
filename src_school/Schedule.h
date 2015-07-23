//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_SCHEDULE_H
#define UMJI_VG101_PROJECT_FOR_SCHEDULE_H


#include "globaldef.h"

class Schedule {
public:
    void addEvent(ClassOfDay,RoomIndex,CourseIndex);
    void removeEvent(ClassOfDay);
    void ToString();
private:
    typedef struct{
        RoomIndex location;
        CourseIndex course;
    }Event;

};


#endif //UMJI_VG101_PROJECT_FOR_SCHEDULE_H
