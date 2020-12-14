#ifndef _COURSE_H_
#define _COURSE_H_

#include <exception>
#include "List.h"
#include "types.h"
#include "Lecture.h"
class Course{
    
    int courseID;
    //Lecture* unwatched_arr;
    ListNode<Lecture>** lecture_arr;
    List<Lecture>* unwatched;
    bool* is_watched;
    int num_of_classes;


    public:
        Course(int courseID,int numOfClasses);
        Course(const Course& copy);
        ListNode<Lecture>**  getLectureArray();
        bool get_watched(int classID) const;
        ListNode<Lecture>*  getUnwatchedRoot() const;
        void setUnwatchedRoot(ListNode<Lecture>* new_root) const;
        int get_id() const;
        int getNumOfClasses();
        void set_watched(int classID);
        void reset_unwatched();


};

#endif