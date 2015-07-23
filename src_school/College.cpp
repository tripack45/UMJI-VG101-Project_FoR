//
// Created by 越 on 2015/7/21.
//

#include "College.h"
#include <list>
std::string College::getName() {
    return name;
}

void College::setName(std::string &strname) {
    name=strname;
    return;
}

void College::AddBuilding(Building *building_) {
    this->building.push_back(building_);
}

void College::AddFaculty(Teacher *teacher_){
    if(teacher_==0)return;
    std::list<Teacher*>::iterator it;
    for(it=teacher.begin();it!=teacher.end();it++)
        if((*it)==teacher_)return;
    this->teacher.push_back(teacher_);
}

void College::AddCourse(Course *course_) {
    if(course_==0)return;
    std::list<Course*>::iterator it;
    for(it=course.begin();it!=course.end();it++)
        if(*it==course_)return;
    for(int i=0;i<course_->getSessionNumber();i++) {
        Session *tsession = new Session(0);
        tsession->session_of_course=i;
        this->session.push_back(tsession);
    }
}

Session College::getCourseArrangements(CourseIndex index) {
    return Session(<#initializer#>, nullptr);
}

Schedule College::getSessionArrangement(SessionIndex index) {
    return Schedule();
}

Schedule College::getFacultySchedule(PersonnelID id) {
    return Schedule();
}

Schedule College::getStudentSchedule(PersonnelID id) {
    return Schedule();
}

void College::ListFaculty() {
    for(int i=0;i<teacher.size();i++)
        teacher[i]->toString;
    }
}

void College::ListStudent() {
    for(int i=0;i<student.size();i++){
        student[i]->toString;
    }

}

void College::ListCourses() {
    for(int i=0;i<course.size();i++)
        course[i]->toString;
}
