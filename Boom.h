#ifndef BOOM_H_
#define BOOM_H_
#include "Avl.h"
#include "Course.h"
#include "BoomDS.h"
#include "StatusType.h"

class Boom{
    public:
    void* init();
    StatusType AddCourse(void *DS,int courseID,int numOfClasses);
    StatusType RemoveCourse(void *DS, int courseID);
    StatusType WatchClass(void *DS, int courseID, int classID, int time);
    StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed);
    StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes);
    void Quit(void **DS);


};

#endif