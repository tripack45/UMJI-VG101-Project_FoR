//
// Created by 越 on 2015/7/21.
//

#include "hw8_college.h"

std::string College::getName() {
    return name;
}

void College::setName(std::string &strname) {
    name=strname;
    return;
}

void College::AddBuilding(Building *building_) {
    if(building_==0) {
        std::cerr<<"Error:Adding NULL building!"<<std::endl;
        return;
    }
    std::list<Building*>::iterator it;
    for(it=building.begin();it!=building.end();it++)
        if((*it)==building_) {
            std::cerr<<"Error: Adding duplicate building"<<std::endl;
            return;
        }
    this->building.push_back(building_);
}

void College::AddFaculty(Teacher *teacher_){
    if(teacher_==0) {
        std::cerr<<"Error:Adding NULL Faculty!"<<std::endl;
        return;
    }
    std::list<Person*>::iterator it;
    for(it=teacher.begin();it!=teacher.end();it++)
        if((*it) == teacher_) {
            std::cerr<<"Error: Adding duplicate faculty"<<std::endl;
            return;
        }
    teacher_->setID(GeneratePersonnelID());
    this->teacher.push_back(teacher_);
}

Section *College::getSectionPtr(SectionIndex index) {
    std::list<Section*>::iterator it;
    for(it=section.begin();it!=section.end();it++) {
        if((*it)->id==index)return *it;
    }
    std::cerr<<"Error: Accessing None-Existing Section Index"<<std::endl;
    return 0;
}

void College::AddCourse(Course *course_) {
    if(course_==0) {
        std::cerr << "Error: Adding NULL course!" << std::endl;
        return;
    }
    std::list<Course*>::iterator it;
    for(it=course.begin();it!=course.end();it++)
        if( (*it)==course_) {
            std::cerr << "Error: Adding duplicate Course!" << std::endl;
            return;
        }
    course_->setCourseIndex(GenerateCourseIndex());
    course.push_back(course_);
    for(int i=0;i<course_->getSectionNumber();i++) {
        Section *tsection = new Section(GenerateSectionID(),course_);
        tsection->section_of_course =i;
        this->section.push_back(tsection);
    }
}

Section College::getCourseArrangements(CourseIndex index){

}

Schedule College::getSessionArrangement(SectionIndex index) {
    return Schedule();
}

Schedule College::getFacultySchedule(PersonnelID id) {
    return Schedule();
}

Schedule College::getStudentSchedule(PersonnelID id) {
    return Schedule();
}

void College::ListFaculty() {
    std::list<Person*>::iterator it;
    for(it=teacher.begin();it!=teacher.end();it++)
        (*it)->toString;
    }
}

void College::ListStudent() {
    std::list<Person*>::iterator it;
    for(it=student.begin();it!=student.end();it++)
        (*it)->toString;
}

void College::ListCourses() {
    std::list<Course*>::iterator it;
    for(it=course.begin();it!=course.end();it++)
        (*it)->toString;
}

void College::SectionAutoMatch(SectionIndex index) {

}

void College::SectionAutoMatch() {

}

void College::SectionMatch(SectionIndex index, PersonnelID id, RoomName room_name) {
    Section* sptr=getSectionPtr(index);
    Person* person_ptr=getPersonPtr(id);
    if(person_ptr->getType()==Instructors){
        sptr->teacher= dynamic_cast<Teacher*>(person_ptr);
    }else{
        std::cerr<<"Error: Arranging Instructor as None-Instructor"<<std::endl;
        return;
    }
    Room* room_ptr=getRoomPtr(room_name);
    sptr->room=room_ptr;
    sptr->IsActive=true;
}

PersonnelID College::GeneratePersonnelID() {
    static PersonnelID idcount;
    idcount++;
    return idcount;
}

CourseIndex College::GenerateCourseIndex() {
    static CourseIndex indexcount;
    indexcount++;
    return indexcount;
}

SectionIndex College::GenerateSectionID() {
    static SectionIndex idcount;
    idcount++;
    return idcount;
}

Person *College::getPersonPtr(PersonnelID id) {
    std::list<Person *>::iterator it;
    for(it=teacher.begin();it!=teacher.end();it++) {
        if((*it)->getID()==id)return *it;
    }
    for(it=student.begin();it!=student.end();it++) {
        if((*it)->getID()==id)return *it;
    }
    std::cerr<<"Error: Accessing None-Existing PersonnelID"<<std::endl;
    return 0;
}

Room *College::getRoomPtr(RoomName name) {
    std::list<Building*>::iterator it;
    for(it=building.begin();it!=building.end();it++)
        if((*it)->getBuildingCode()==name.building)
            if(name.floor<=(*it)->getFloorNumber())
                if(name.number<=(*it)->getRoomNumber())
                    return (*it)->getRoomPtr(name.floor,name.number);
    std::cerr<<"Error: Accessing None-Existing RoomName"<<std::endl;
    return 0;
}

void College::SectionAutoMatch(SectionIndex index, PersonnelID id) {

}
