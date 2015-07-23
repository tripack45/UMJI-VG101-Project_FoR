//
// Created by 越 on 2015/7/21.
//

#ifndef UMJI_VG101_PROJECT_FOR_BUILDING_H
#define UMJI_VG101_PROJECT_FOR_BUILDING_H

#include <iostream>
#include <vector>
#include "Room.h"

class Building {
public:
    typedef int RoomIndex;
    Building(int floors, int rooms);
    int getRoomNumber();
    int getFloorNumber();
    int getFreeRoom();
    void AssignRooms(int count, RoomType type);
    void AssignNameChar(char);
    ~Building();

private:
    int floor_count;
    int room_count;
    Room** room;

    int assigned_rooms;//Rooms Already
};


#endif //UMJI_VG101_PROJECT_FOR_BUILDING_H
