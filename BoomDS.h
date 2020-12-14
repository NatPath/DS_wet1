#ifndef _BOOMDS_H_
#define _BOOMDS_H_
#include "types.h"
#include "Avl.h"
#include "List.h"
#include "Lecture.h"
#include "Course.h"
#include "library.h"



class BoomDS{
    
    AVL_Tree<int,Course> courses;
    AVL_Tree<Lecture,Lecture> lectures;
    std::shared_ptr<AVL_NODE<Lecture,Lecture>> most_watched;
    std::shared_ptr<AVL_NODE<int,Course>> smallest_id;

    void removeFromUnwatched(Course& watched_course,ListNode<Lecture>* watched);
    void reverseClimbLectures(std::shared_ptr<AVL_NODE<Lecture,Lecture>> root, bool goUp,bool goRight, bool goLeft,int *index, int *courses, int *classes, int m );
    void reverseClimbCourses(std::shared_ptr<AVL_NODE<int,Course>> root, bool goUp,bool goRight, bool goLeft,int *index, int *courses, int *classes, int m );
    public:
        BoomDS()=default;
        
        StatusType AddCourse(int courseID,int numOfClasses);
        StatusType RemoveCourse(int courseID);
        StatusType WatchClass(int courseID, int classID, int time);
        StatusType TimeViewed( int courseID, int classID, int *timeViewed);
        StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);
        


};

#endif