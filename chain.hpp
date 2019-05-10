#include "range.hpp"
//#include "pair.hpp"
using namespace std;

namespace itertools{

template <typename T,typename E>
 class chain{
     private:
     T t;
     E e;

     public:

     chain<T,E>(const T t0 , const E e0):
     t(t0),e(e0){}

    class iterator{

    private:
    typename T::iterator lit;
    typename T::iterator end_lit;
    typename E::iterator rit; 

    public:

    iterator(typename T::iterator otherT ,typename E::iterator otherE ,typename T::iterator endT):
        lit(otherT),rit(otherE),end_lit(endT)
    {}

    iterator& operator ++(){
        if(lit.t != end_lit.t){
            ++lit;
        }
        else{
        ++rit;
        }
       return *this;
    }

    bool operator !=(const iterator& t0){
        return (this->lit != t0.lit || this->rit != t0.rit);
    }

    
    auto operator *(){
        if (lit != end_lit)
        {
            return *lit;
        }
        else
        {
            return *rit;
        }
        }
        
        //return pair(*lit,*rit);
        };

    iterator begin(){
            return iterator(t.begin(),e.begin(),t.end());
        }
    iterator end(){
            return iterator(t.end(),e.end(),t.end());
        }


 };

}