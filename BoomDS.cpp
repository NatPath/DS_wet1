#include "BoomDS.h"

// add find function in avl that gets a node's key and returns a pointer to the required node's data.
// add > operator to lecture, will just call > operator of lecture key
// todo: add getwatchedclasses
// add failures
//add option to return inserted node to tree

StatusType BoomDS::AddCourse(int courseID,int numOfClasses){
    Course *insert = new Course(courseID,numOfClasses);
    //check memory allocation in AVL
    courses.insertNode(insert);
    if(largest_id == nullptr || courseID > largest_id->getValue().get_id()){
        largest_id=std::shared_ptr<AVL_NODE<Course>>(insert);
    }
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
    ListNode<Lecture>* watched_lecture = (watched_course->getLectureArray())[classID];
    int old_time = watched_lecture->getValue()->getViews();
    LectureKey key = LectureKey(courseID,classID,old_time);
    //check if this doesn't free the object
    lectures.deleteNode(key);
    watched_lecture->getValue()->addViews(time);
    Lecture* to_add = watched_lecture->getValue().get();
    std::shared_ptr<AVL_NODE<Lecture>> inserted = lectures.insertNode(to_add);

    if(most_watched==nullptr || *to_add>most_watched->getValue()){
        most_watched = inserted;
    }

    if(!watched_course->get_watched(classID)){
        removeFromUnwatched(watched_course,watched_lecture);
        watched_course->set_watched(classID);
    }

    return StatusType::SUCCESS;

}

StatusType BoomDS::TimeViewed( int courseID, int classID, int *timeViewed){
    Course* watched_course = courses.find(courseID);
    ListNode<Lecture>* watched_lecture = (watched_course->getLectureArray())[classID];
    *timeViewed = watched_lecture->getValue()->getViews();
    return StatusType::SUCCESS;
}

StatusType BoomDS::GetMostViewedClasses(int numOfClasses, int *courses, int *classes){
    int* index;
    *index = 0;
    reverseClimbLectures(most_watched,true,true,true,index,courses,classes,numOfClasses);
    if(index<numOfClasses){
        reverseClimbCourses(largest_id,true,true,true,index,courses,classes,numOfClasses);
    }
}



void reverseClimbLectures(std::shared_ptr<AVL_NODE<Lecture>> root, bool goUp,bool goRight, bool goLeft,int *index, int *courses, int *classes, int m ){

    if(!root || *index >=m){
        return;
    }
    // go right
    if(root->getRight() && goRight){
        reverseClimbLectures(root->getRight(),false,true,true,index,courses,classes,m);
    }

    // save this node
    courses[*index] = root->getValue().getCourseID();
    classes[*index] = root->getValue().getLectureID();
    *index+=1;


    // go left
    if(root->getLeft() && goLeft){
        reverseClimbLectures(root->getLeft(),false,true,true,index,courses,classes,m);
    }

    // go up
    if(root->getParent() && goUp){
        // decide if this is the right or left child so we don't return here
        // add > operator to lecture, just activate the > operator of LectureKey
        if(root->getValue() > root->getParent()->getValue() ){
            // this was the right child, don't go right again
           reverseClimbLectures(root->getParent(),true,false,true,index,courses,classes,m);
        }
        else{
            reverseClimbLectures(root->getParent(),true,true,false,index,courses,classes,m);
        }

    }

}


void reverseClimbCourses(std::shared_ptr<AVL_NODE<Course>> root, bool goUp,bool goRight, bool goLeft,int *index, int *courses, int *classes, int m ){

    if(!root || *index >=m){
        return;
    }
    // go right
    if(root->getRight() && goRight){
        reverseClimbCourses(root->getRight(),false,true,true,index,courses,classes,m);
    }

    std::shared_ptr<ListNode<Lecture>> i = root->getValue().getUnwatchedRoot();
    while(*index<m && i ){
        courses[*index] = i->getValue()->getCourseID();
        classes[*index] = i->getValue()->getLectureID();
        *index+=1;
        i = i->getNext();

    }
    


    // go left
    if(root->getLeft() && goLeft){
        reverseClimbCourses(root->getLeft(),false,true,true,index,courses,classes,m);
    }

    // go up
    if(root->getParent() && goUp){
        // decide if this is the right or left child so we don't return here
        // add > operator to lecture, just activate the > operator of LectureKey
        if(root->getValue() > root->getParent()->getValue() ){
            // this was the right child, don't go right again
           reverseClimbCourses(root->getParent(),true,false,true,index,courses,classes,m);
        }
        else{
            reverseClimbCourses(root->getParent(),true,true,false,index,courses,classes,m);
        }

    }

}


void removeFromUnwatched(Course* watched_course,ListNode<Lecture>* watched){
    if(!watched->getNext() && !watched->getPrev()){
        //only lecture
        watched_course->reset_unwatched();
    }
    else if(!watched->getNext()){
        //remove last
        watched->getPrev()->connectNext(nullptr);
    }
    else if(!watched->getPrev()){
        //remove first
        watched->getNext()->connectPrev(nullptr);
    }
    else{
        //remove in the middle of the list
        watched->getPrev()->connectNext(watched->getNext());
        watched->getNext()->connectPrev(watched->getPrev());
    }

    // node should still exist because of the pointer in lecture_arr, so remove any connections
    watched->connectPrev(nullptr);
    watched->connectNext(nullptr);
}



 