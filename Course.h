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


    public:
        Course(int courseID,int numOfClasses);
        Course(const Course& copy);
        ListNode<Lecture>**  getLectureArray();
        bool get_watched(int classID) const;
        std::shared_ptr<ListNode<Lecture>> getUnwatchedRoot() const;
        int get_id() const;
        void set_watched(int classID);
        void reset_unwatched();


};

#endif