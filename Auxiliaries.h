#ifndef _AUX
#define _AUX
#include <exception>
#include <iostream>


template<class T>
T& max(const T& a,const T& b){
    return a<b?b:a; 
}
template<class T>
void print(const T& to_print){
    std::cout<<to_print<<std::endl;
}

#endif 