#ifndef _COURSE_H_
#define _COURSE_H_
#include "Lecture.h"
#include "List.h"
class Course{

    int courseId;
    Lecture* unwatched;
    List<Lecture>* lectures;


    public:
        Course(int courseId,int numOfClasses);
    


};

#endif