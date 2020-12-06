#ifndef _LECTURE_H_
#define _LECTURE_H_

class Lecture{

    int courseID;
    int lectureID;
    int num_views;

    public:
    Lecture(int courseID, int lectureID):courseID(courseID),lectureID(lectureID),num_views(0){}
    void addViews(int to_add){
        num_views+=to_add;
    }
    int getViews() const{
        return num_views;
    }
    int getCourseID() const{
        return courseID;
    }
    int getLectureID() const{
        return lectureID;
    }
    bool operator==(const Lecture& compare) const;
    bool operator!=(const Lecture& compare) const;
        
    bool operator>(const Lecture& compare) const;
    bool operator<(const Lecture& compare) const;
                
};

#endif