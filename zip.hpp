#include "range.hpp"
#include "pair.hpp"
using namespace std;

namespace itertools{

template <typename T,typename E>
 class zip{
     private:
     T t;
     E e;

     public:

     zip<T,E>(const T t0 , const E e0):
     t(t0),e(e0){}

    class iterator{


    private:
    typename T::iterator lit;
    typename E::iterator rit; 

    public:

    iterator(typename T::iterator otherT ,typename E::iterator otherE):
        lit(otherT),rit(otherE)
    {}

    iterator& operator ++(){
        ++lit;
        ++rit;
        return *this;
    }

    bool operator !=(const iterator& t0){
        return (this->lit != t0.lit || this->rit != t0.rit);
    }

    auto operator *(){
        //return pair(lit.t,rit.t);
        return pair(*lit,*rit);
    }
        
        };

    iterator begin(){
            return iterator(t.begin(),e.begin());
        }
    iterator end(){
            return iterator(t.end(),e.end());
        }

    };


}