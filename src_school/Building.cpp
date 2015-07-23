//
// Created by 越 on 2015/7/21.
//

#include "hw8_college.h"
#include "globaldef.h"
#include <iostream>

Building::Building(int floors_, int rooms_) {
    this->room_count    =   floors_;
    this->floor_count   =   rooms_;
    room=new Room*[floors_ * rooms_];
    for(int i=0;i<floors_;i++)
        for(int j=0;j<rooms_;j++) {
            RoomName tname;
            tname.floor=i;
            tname.number=j;
            room[i * floors_ + j] = new Room(tname);
        }
}

int Building::getRoomNumber() {
    return room_count;
}

int Building::getFloorNumber() {
    return floor_count;
}

Building::~Building() {
    for(int i=0;i<getRoomNumber()*getFloorNumber();i++){
        delete (room + i);
    }
    delete room;
}

void Building::AssignRooms(int count, RoomType type){
    if(count<=0)return;
    for(int i=0;i<count;i++) {
        if( i+assigned_rooms >= room_count*floor_count){
            std::cerr<<"Error:Not Enough Rooms, "
                <<i<<" of "<<count<<" rooms (TypeNum:"
                <<type<<") assigned.";
            return;
        }
        room[assigned_rooms]->setType(type);
    }
    return;
}

int Building::getFreeRoom() {
    return floor_count*room_count-assigned_rooms;
}

void Building::AssignNameChar(char c) {
    for(int i=0;i<floor_count*room_count;i++){
        RoomName tname=room[i]->getRoomName();
        tname.building=c;
        room[i]->setRoomName(tname);
    }
}
