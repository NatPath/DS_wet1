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
    List<Lecture> unwatched;
    bool* is_watched;
    int num_of_classes;


    public:
        Course(int courseID,int numOfClasses);
        Course(const Course& copy);
        Course& operator=(const Course& copy);
        ListNode<Lecture>**  getLectureArray();
        Lecture& getLecture(int classID);
        /*
        * returns wether the class with the given ID has been watched already
        */
        bool get_watched(int classID) const;
        /*
        *returns a ponter to the root of the list of the unwatched courses
        */
        ListNode<Lecture>*  getUnwatchedRoot() const;
        /*
        *sets the root of the Unwatched list to be 'new_root'
        */
        void setUnwatchedRoot(ListNode<Lecture>* new_root) ;
        /*
        * returns course ID
        */
        int get_id() const;
        /*
        * returns number of classes
        */
        int getNumOfClasses();
        /*
        * mark classID as a watched class in the is_watched array
        */
        void set_watched(int classID);
        /*
        * ???
        */
        void reset_unwatched();
        

        ~Course();


};

#endif