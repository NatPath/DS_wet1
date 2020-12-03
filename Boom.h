#ifndef BOOM_H_
#define BOOM_H_
#include "Avl.h"
#include "Course.h"

class Boom{
    AVL_Tree<Course> courses;
    AVL_Tree<Lecture> lectures;
    public:
    void* init();
    StatusType AddCourse(void *DS,int courseID,int numOfClasses);

};

#endif