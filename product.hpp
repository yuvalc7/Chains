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
    typename T::iterator lit;
    typename E::iterator rit;
    typename T::iterator end_lit;
    typename E::iterator end_rit;
    typename E::iterator r_start;

    public:

    iterator(typename T::iterator otherT ,typename E::iterator otherE ,typename T::iterator endT,typename E::iterator endE):
        lit(otherT),rit(otherE),end_lit(endT),end_rit(endE),r_start(otherE)
    {}
    bool operator !=(const iterator& it){
        return (lit != it.lit || rit != it.rit);
    }

    iterator& operator++(){
        
            if (rit != end_rit )
            {
                if (++rit != end_rit){

                }
                else
                {
                    if (lit != end_lit)
                    {
                        if (++lit != end_lit){
                            rit = r_start;
                        }
                    }
                    
                }
            }
            else{
                ++lit;
                rit= r_start;
            }
    
        return *this;
    }
    auto operator *(){
        return pair(*lit,*rit);
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