#include "vec.hpp"
#include<math.h>
#include<iostream>
namespace itertools{
template <typename T>
class powerset{

    private:
    T t;

    public:

    powerset<T>(const T t0) : t(t0){}
    template<typename E>
    class iterator{

    private:
    E start; // start point
    E _end; // end point
    unsigned int _size; // size of sets
    unsigned int index;
    public:

    iterator(E s , E e) :
    start(s) , _end(e) , _size(0) , index(0){
        E temp_s = start;
          while(temp_s != _end){
            _size++;
            temp_s++;
          }
        _size = pow(2,_size);
    }

    auto operator *(){
    std::vector<decltype(*start)> s; // where we store all sets/values
    E _start = start;// save start point to know where to begin
    unsigned int i = index;
    while( i != 0 && _start != _end){
        unsigned int bit = i%2; // check if bit is 1 or 0
        i = i >> 1; // move 1 bit to the right
        if(bit == 1){
            s.emplace_back(*_start);
        }
        ++_start;
    }
    return s;
    }

    bool operator ++() {
        index++;
        return *this;
    }

    iterator& operator !=(const iterator &it){
     return index != it._size;

    }



};
        iterator<decltype(t.begin())> begin()const{
            return iterator<decltype(t.begin())>(t.begin() , t.end());
        }
        iterator <decltype(t.end())> end()const{
            return iterator<decltype(t.end())>(t.begin() , t.end());
        }

};

}
