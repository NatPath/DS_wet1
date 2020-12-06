#include "Lecture.h"


bool Lecture::operator==(const Lecture& compare) const{
    return num_views==compare.getViews()&&courseID==compare.getCourseID()&&lectureID==compare.getLectureID();
}
bool Lecture::operator!=(const Lecture& compare) const{
    return !(compare==*this);
}
bool Lecture::operator>(const Lecture& compare) const{
    if (num_views > compare.getViews()){
        return true;
    }
    if (num_views < compare.getViews()){
        return false;
    }
    // num_views == compare.getViews()
    if (courseID > compare.getCourseID()){
        return true;
    }
    if (courseID < compare.getCourseID()){
        return false;
    }
    // num_views == compare.getViews() && courseId==compare.getCourseId()
    if (lectureID > compare.getLectureID()){
        return true;
    }
    else{
        return false;
    }

}
bool Lecture::operator<(const Lecture& compare) const{
    return !(*this>compare)&&(*this!=compare);
}