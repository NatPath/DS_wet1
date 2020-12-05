#include "Course.h"

Course::Course(int courseID, int numOfClasses){
    this->courseID = courseID;
    //this->unwatched_arr = new Lecture[numOfClasses];
    lecture_arr = new ListNode<Lecture>*[numOfClasses];
    unwatched = new List<Lecture>();
    is_watched = new bool[numOfClasses];
    for(int i = 0; i<numOfClasses; i++){
        lecture_arr[i] = new ListNode<Lecture>(std::make_shared<Lecture>(i));
        is_watched[i] = false;
    }

    for(int i = numOfClasses-1; i>=0; i--){
        unwatched->add(*lecture_arr[i]);
    }

    
}

bool Course::get_watched(int classID) const{
    return is_watched[classID];
}

int Course::get_id() const{
    return courseID;
}

void Course::set_watched(int classID){
    is_watched[classID] = true;
}

void Course::reset_unwatched(){
    unwatched = nullptr;
}

ListNode<Lecture>** Course::getLectureArray(){
    return lecture_arr;
}

std::shared_ptr<ListNode<Lecture>> Course::getUnwatchedRoot() const{
    return unwatched->getRoot();
}

