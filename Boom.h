#ifndef BOOM_H_
#define BOOM_H_
#include "Avl.h"
<<<<<<< HEAD
#include "library.h"

=======
#include "Course.h"
>>>>>>> 271ee96c7b009d78f9fcb629a5addfb693f331d7

class Boom{
    AVL_Tree<Course> courses;
    AVL_Tree<Lecture> lectures;
    public:
    void* init();
    StatusType AddCourse(void *DS,int courseID,int numOfClasses);

};

#endif