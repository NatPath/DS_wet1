#include "Course.h"

Course::Course(int courseID, int numOfClasses){
    this->courseID = courseID;
    //this->unwatched_arr = new Lecture[numOfClasses];
    lecture_arr = new Lecture_ptr[numOfClasses];
    unwatched = new List<Lecture_ptr>();
    for(int i = 0; i<numOfClasses; i++){
        lecture_arr[i] = std::make_shared<Lecture>(courseID,i);
    }

    for(int i = numOfClasses-1; i>=0; i--){
        unwatched->add(lecture_arr[i]);
    }

    
}

Lecture_ptr* Course::getLectureArray(){
    return lecture_arr;
}

