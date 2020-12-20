#include "Course.h"

Course::Course(int courseID, int numOfClasses){
    this->courseID = courseID;
    this->num_of_classes=numOfClasses;
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

     for(int i = num_of_classes-1; i>=0; i--){
        if(!is_watched[i]) {
            unwatched.add(lecture_arr[i]);
        }
    }
    
}


Course& Course::operator=(const Course& copy){

    ListNode<Lecture>** lecture_arr_tmp = new ListNode<Lecture>*[copy.num_of_classes];
    bool* is_watched_tmp=new bool[copy.num_of_classes];

    try
    {

        for (int i = 0; i < copy.num_of_classes; i++)
        {
            lecture_arr_tmp[i] = new ListNode<Lecture>();
            *lecture_arr_tmp[i] = *copy.lecture_arr[i];
            is_watched_tmp[i] = copy.is_watched[i];
        }


        for (int i = 0; i < num_of_classes; i++)
        {
            if (is_watched[i])
            {
                delete lecture_arr[i];
            }
        }

        delete[] lecture_arr;
        delete[] is_watched;

        courseID = copy.courseID;

        num_of_classes = copy.num_of_classes;

        lecture_arr = lecture_arr_tmp;
        is_watched = is_watched_tmp;

        unwatched.~List();
        unwatched = List<Lecture>();

        for (int i = num_of_classes - 1; i >= 0; i--)
        {
            if(!is_watched[i]){
                unwatched.add(lecture_arr[i]);
            }
        }
    }
    catch (...)
    {
        for(int i=0;i<copy.num_of_classes;i++){
            if(is_watched_tmp[i]){
                delete lecture_arr_tmp[i];
            }
         }
        delete[] lecture_arr_tmp;
        delete[] is_watched_tmp;
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

Lecture& Course::getLecture(int classID){
    return *lecture_arr[classID]->getValue();
}

Course::~Course(){
    
    for(int i=0;i<num_of_classes;i++){
        if(is_watched[i]){
            delete lecture_arr[i];
        }
    }
    
    delete[] lecture_arr;
    delete[] is_watched;
}

