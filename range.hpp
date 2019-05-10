#pragma once
#include <iostream>

namespace itertools
{
template<typename T> 
class range{
    public:

T t1;
T t2;

range<T>(const T t0,const T t3):
    t1(t0),t2(t3)
{}

class iterator{
    public:
    T t;

    iterator(T other):
        t(other)
    {}

   iterator& operator ++(){
       t++;
       return *this;
    }

    bool operator !=(const iterator& t0){
        return t != t0.t;
    }
    
    T operator *(){
        return t;
    }



};

iterator begin(){
    return range<T>::iterator(t1);
}
iterator end(){
    return range<T>::iterator(t2);
}



};
}


