#ifndef _AUX
#define _AUX
#include <exception>


template<class T>
T& max(const T& a,const T& b){
    return a<b?b:a; 
}

#endif 