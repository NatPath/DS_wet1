#include "Course.h"

Course::Course(int courseId, int numOfClasses){
    this->courseId = courseId;
    this->unwatched = new Lecture[numOfClasses];
    this->lectures = new List<Lecture>();
}