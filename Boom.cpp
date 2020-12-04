#include "Boom.h"

void* Boom::init(){
    return new BoomDS();
}

StatusType AddCourse(void *DS,int courseID,int numOfClasses){
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->AddCourse(courseID,numOfClasses);
}

StatusType RemoveCourse(void *DS, int courseID){
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->RemoveCourse(courseID);
}

StatusType WatchClass(void *DS, int courseID, int classID, int time){
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->WatchClass(courseID, classID, time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed){
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->TimeViewed(courseID, classID, timeViewed);
}

StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes){
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->GetMostViewedClasses(numOfClasses,courses,classes);
}