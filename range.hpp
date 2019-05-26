#pragma once
#include <iostream>

namespace itertools
{
template<typename T>
class range{

    private:
    T _start;
    T _end;

    public:
    range(const T start,const T end):
    _start(start),_end(end)
    {}

class iterator{
    private:
    T current;

    public:
    //constructor
    iterator(T o):
        current(o)
    {}

    iterator& operator ++(){
       current++;
       return *this;
    }

    bool operator ==(const iterator& e) const{
       return current == e.current;
    }

    bool operator !=(const iterator& t0)const{
        return current != t0.current;
    }

    auto operator *(){
        return current;
    }
};

        /*

    class pair{
        private:
        typename K k;
        typename E e;

        public:
        pair(const range& r):
        k(r.t1),e(r.t2){}

    };

    */
    iterator begin() const{
    return iterator(_start);
    }
    iterator end() const{
    return iterator(_end);
    }



};
}


