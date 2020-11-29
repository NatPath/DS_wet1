#ifndef BOOM_H_
#define BOOM_H_
#include "Avl.h"


class Boom{
    AVL root;
    public:
    void* init();
    StatusType AddCourse(void *DS,int courseID,int numOfClasses);

}

#endif