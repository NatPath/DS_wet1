#ifndef _COURSE_H_
#define _COURSE_H_

#include "List.h"
#include "types.h"
class Course{
    
    int courseID;
    //Lecture* unwatched_arr;
    Lecture_ptr* lecture_arr;
    List<Lecture_ptr>* unwatched;


    public:
        Course(int courseID,int numOfClasses);
        Course(const Course& copy);
        Lecture_ptr* getLectureArray();
        
        
    


};

#endif