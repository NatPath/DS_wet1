#include "Course.h"

Course::Course(int courseID, int numOfClasses){
    this->courseID = courseID;
    this->num_of_classes=numOfClasses;
    //this->unwatched_arr = new Lecture[numOfClasses];
    try{
        lecture_arr = new ListNode<Lecture>*[numOfClasses];
        unwatched = List<Lecture>();
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
        unwatched.add(lecture_arr[i]);
    }

    
}
Course::Course(const Course& copy){
    courseID=copy.courseID;
    unwatched= List<Lecture>();
    num_of_classes=copy.num_of_classes;
    lecture_arr = new ListNode<Lecture>*[copy.num_of_classes];
    is_watched=new bool[num_of_classes];
    
    for(int i =0; i<num_of_classes;i++){
        lecture_arr[i]= new ListNode<Lecture>();
        *lecture_arr[i] = *copy.lecture_arr[i];
        is_watched[i] = copy.is_watched[i];
    }

    for(int i =0; i<num_of_classes-1;i++){
        lecture_arr[i]->connectNext(lecture_arr[i+1]);
    }

     for(int i = num_of_classes-1; i>=0; i--){
        unwatched.add(lecture_arr[i]);
    }
    
   
    

    
}

Course&  Course::operator=(const Course& copy){
    courseID=copy.courseID;
    unwatched= List<Lecture>();
    num_of_classes=copy.num_of_classes;
    lecture_arr = new ListNode<Lecture>*[copy.num_of_classes];
    is_watched=new bool[num_of_classes];
    
    for(int i =0; i<num_of_classes;i++){
        lecture_arr[i]= new ListNode<Lecture>();
        *lecture_arr[i] = *copy.lecture_arr[i];
        is_watched[i] = copy.is_watched[i];
    }

    for(int i =0; i<num_of_classes-1;i++){
        lecture_arr[i]->connectNext(lecture_arr[i+1]);
    }

     for(int i = num_of_classes-1; i>=0; i--){
        unwatched.add(lecture_arr[i]);
    }

    return *this;
    

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
    return unwatched.getRoot();
}

void Course::setUnwatchedRoot(ListNode<Lecture>* new_root) {
    unwatched.setRoot(new_root);
}

Course::~Course(){

    //delete unwatched;
    
    for(int i=0;i<num_of_classes;i++){
        if(is_watched[i]){
            delete lecture_arr[i];
        }
        
    }

    
    delete[] lecture_arr;
    delete[] is_watched;
}

