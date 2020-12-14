#include "Course.h"

Course::Course(int courseID, int numOfClasses){
    this->courseID = courseID;
    this->num_of_classes=numOfClasses;
    //this->unwatched_arr = new Lecture[numOfClasses];
    try{
        lecture_arr = new ListNode<Lecture>*[numOfClasses];
        unwatched = new List<Lecture>();
        is_watched = new bool[numOfClasses];
        for(int i = 0; i<numOfClasses; i++){
            lecture_arr[i] = new ListNode<Lecture>(std::make_shared<Lecture>(courseID,i));
            is_watched[i] = false;
        }
    }
    catch(const std::exception& e){
        throw e;
    }

    for(int i = numOfClasses-1; i>=0; i--){
        unwatched->add(lecture_arr[i]);
    }

    
}
Course::Course(const Course& copy){
    courseID=copy.courseID;
    lecture_arr=copy.lecture_arr;
    unwatched=copy.unwatched;
    is_watched=copy.is_watched;
    num_of_classes=copy.num_of_classes;
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

int Course::getNumOfClasses(){
    return num_of_classes;

}
ListNode<Lecture>** Course::getLectureArray(){
    return lecture_arr;
}

ListNode<Lecture>*  Course::getUnwatchedRoot() const{
    return unwatched->getRoot();
}

void Course::setUnwatchedRoot(ListNode<Lecture>* new_root) const {
    unwatched->setRoot(new_root);
}

