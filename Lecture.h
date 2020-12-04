#ifndef _LECTURE_H_
#define _LECTURE_H_

class Lecture{

    int courseID;
    int lectureId;
    int num_views;

    public:
    Lecture(int courseID, int lectureId):courseID(courseID),lectureId(lectureId),num_views(0){}
    void addViews(int to_add){
        num_views+=to_add;
    }
    int getViews(){
        return num_views;
    }

};

#endif