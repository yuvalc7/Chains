#pragma once
#include<vector>
#include<iostream>

using namespace std;
namespace itertools{

template<typename T>
ostream& operator<<(std::ostream& os , const std::vector<T> &_vector){
     if(_vector.empty()){
        os<<"{"<<"}";
        return os;
     }
     size_t i = 0 ;
     os<<"{";
     while( i < _vector.size() - 1){
        os<_vector[i]<<",";
        i++;
     }
     os<<_vector[i]<<"}";
     return os;
    }




}
