#include "BoomDS.h"

// add find function in avl that gets a node's key and returns a pointer to the required node's data.
// todo: add getwatchedclasses

StatusType BoomDS::AddCourse(int courseID,int numOfClasses){
    Course *insert = new Course(courseID,numOfClasses);
    //check memory allocation in AVL
    courses.insertNode(insert);
    return StatusType::SUCCESS;
}

StatusType BoomDS::RemoveCourse(int courseID){
    /*
    Course del = Course(courseID,1);
    courses.deleteNode(del);
    return StatusType::SUCCESS;
    */
    courses.deleteNode(courseID);
    return StatusType::SUCCESS;
}

StatusType BoomDS::WatchClass(int courseID, int classID, int time){
    Course* watched_course = courses.find(courseID);
    Lecture_ptr watched_lecture = (watched_course->getLectureArray())[classID];
    int old_time = watched_lecture->getViews();
    LectureKey key = LectureKey(courseID,classID,old_time));
    //check if this doesn't free the object
    lectures.deleteNode(key);
    watched_lecture->addViews(time);
    Lecture* to_add = watched_lecture.get();
    lectures.insertNode(to_add);

    return StatusType::SUCCESS;

}

StatusType BoomDS::TimeViewed( int courseID, int classID, int *timeViewed){
    Course* watched_course = courses.find(courseID);
    Lecture_ptr watched_lecture = (watched_course->getLectureArray())[classID];
    *timeViewed = watched_lecture->getViews();
    return StatusType::SUCCESS;
}



 