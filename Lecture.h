#ifndef _LECTURE_H_
#define _LECTURE_H_

class Lecture{

    int courseID;
    int lectureID;
    int num_views;

    public:
    Lecture(int courseID, int lectureID,int time=0):courseID(courseID),lectureID(lectureID),num_views(time){}
    //increse number of views by 'to_add'
    void addViews(int to_add){
        num_views+=to_add;
    }
    //number of views getter
    int getViews() const{
        return num_views;
    }
    //courseID getter
    int getCourseID() const{
        return courseID;
    }
    //lectureID getter
    int getLectureID() const{
        return lectureID;
    }
    /*
    * Two Lectures are equal iff all their fields are the same
    */
    bool operator==(const Lecture& compare) const;
    /*
    * Two Lectures are different if they are not equal
    */
    bool operator!=(const Lecture& compare) const;
        
    /*
    * Lectures are ordered by:
    *  first- by number of views ( Biggest first)
    *  second- by CourseID (Smallest first)
    *  third - by LectureID (Smallest first)
    */
    bool operator>(const Lecture& compare) const;
    /*
    * Lectures are ordered by:
    *  first- by number of views ( Biggest first)
    *  second- by CourseID (Smallest first)
    *  third - by LectureID (Smallest first)
    */
    bool operator<(const Lecture& compare) const;
    bool operator>=(const Lecture& compare) const;
    bool operator<=(const Lecture& compare) const;
                
};

#endif