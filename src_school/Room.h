//
// Created by 越 on 2015/7/21.
//
#ifndef UMJI_VG101_PROJECT_FOR_ROOM_H
#define UMJI_VG101_PROJECT_FOR_ROOM_H

#include "Course.h"
#include "globaldef.h"

class Room {
public:
    Room(RoomName);
    void setRoomName(RoomName);
    RoomName getRoomName();
    RoomType getType();
    void setType(RoomType);
private:
    RoomType type;
};


#endif //UMJI_VG101_PROJECT_FOR_ROOM_H
