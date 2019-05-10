#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace itertools
{

template<typename T,typename E> 
class pair{

    public:
    T t;
    E e;

    pair<T,E>(const T t0,const E e0):
    t(t0) , e(e0) {}

    friend ostream& operator<<(ostream& os, const pair& p){
        os << p.t << "," << p.e;
        //os << ",";
        //string printUnit = to_string(*t) + "," + to_string(*e);
        //os << p.e;
        return os;
    }
};

}