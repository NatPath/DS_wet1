#ifndef BOOMDS_H_
#define BOOMDS_H_
#include "Avl.h"
#include "Course.h"
#include "StatusType.h"



class BoomDS{
    AVL_Tree<Course> courses;
    AVL_Tree<Lecture> lectures;
    std::shared_ptr<AVL_NODE<Lecture>> most_watched;
    public:
        BoomDS()=default;
        StatusType AddCourse(int courseID,int numOfClasses);
        StatusType RemoveCourse(int courseID);
        StatusType WatchClass(int courseID, int classID, int time);
        StatusType TimeViewed( int courseID, int classID, int *timeViewed);
        StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);


};

#endif