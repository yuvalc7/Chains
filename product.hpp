#include "range.hpp"
#include <iostream>
#include "pair.hpp"

namespace itertools{
template <typename T,typename E>
class product{

private:
T t;
E e;

public:

product<T,E>(T t0 , E e0):
t(t0) , e(e0){}

class iterator{

    private:
    typename T::iterator first_It;
    typename E::iterator second_It;
    typename T::iterator end_first;
    typename E::iterator end_second;
    typename E::iterator second_start;

    public:

    iterator(typename T::iterator otherT ,typename E::iterator otherE ,typename T::iterator endT,typename E::iterator endE):
        first_It(otherT),second_It(otherE),end_first(endT),end_second(endE),second_start(otherE)
    {}
    bool operator !=(const iterator& it){
        return ((first_It != it.first_It) || (second_It != it.second_It));
    }

    iterator& operator++(){// in this operator function we need to check the current index in each It to be able perform Cartesian multiply

            if (second_It != end_second )
            {
                if(++second_It != end_second){}
                else{ // the index of second It is the last one
                    if (first_It != end_first)
                    {
                        if (++first_It != end_first){ // check the index of first It isn't the last one
                            second_It = second_start;
                        }
                    }
            }
            }
        return *this;
    }
    auto operator *(){
        return pair<T,E>(*first_It,*second_It);
    }

};

    iterator begin(){
            return iterator(t.begin(),e.begin(),t.end(),e.end());
        }
    iterator end(){
            return iterator(t.end(),e.end(),t.end(),e.end());
        }

};
}
