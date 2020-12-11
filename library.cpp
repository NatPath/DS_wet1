#include "library.h"
#include "BoomDS.h"

void* Init(){
    BoomDS *DS = new BoomDS();
    return (void*)DS;
}

void Quit(void** DS){
    delete DS;
}



StatusType AddCourse(void *DS,int courseID,int numOfClasses){
    if(!DS || courseID<=0 || numOfClasses<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->AddCourse(courseID,numOfClasses);
}

StatusType RemoveCourse(void *DS, int courseID){
    if(!DS || courseID<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->RemoveCourse(courseID);
}

StatusType WatchClass(void *DS, int courseID, int classID, int time){
    if(!DS || courseID<=0 || classID<0 || time<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->WatchClass(courseID, classID, time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed){
    if(!DS || courseID<=0 || classID<0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->TimeViewed(courseID, classID, timeViewed);
}

StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes){
    if(!DS || numOfClasses<=0){
        return StatusType::INVALID_INPUT;
    }
    BoomDS* converted = static_cast<BoomDS*>(DS);
    return converted->GetMostViewedClasses(numOfClasses,courses,classes);
}