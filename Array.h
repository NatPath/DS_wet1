#ifndef _ARRAY_H
#define _ARRA_H
#include "Auxiliaries.h"

template <class T>
class Array{
    T* _data;
    int _size;
    public:
    Array(int size){
        _size=size;
        _data= new T[size];

    }
    Array(int size,T default_value){
        _size=size;
        _data=new T[size];
        for (int i=0;i<_size;i++){
            _data[i]=default_value;
        }
    }
    Array(Array& to_copy){
        _size=to_copy.getSize();
        _data=new T[_size];
        for (int i=0;i<_size;i++){
            _data[i]=to_copy[i];
        }
    }
    int getSize() const{
        return _size;
    }
    T* getHead(){
        return _data;
    }

    T& operator[](int index){
        if (index<_size){
            return _data[index];
        }
        else{
            throw std::runtime_error("Out of range index");
        }

    }

    ~Array(){
        delete[] _data;
    }
    void printArray(){
        for (int i=0;i<_size;i++){
            print(_data[i]);
        }
    }

};

#endif 