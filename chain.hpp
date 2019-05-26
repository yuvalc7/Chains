#include "range.hpp"

using namespace std;

namespace itertools{

template <typename T,typename E>
 class chain{
     private:
     T first;
     E sec;

     public:

     chain(const T _first , const E _sec):
     first(_first),sec(_sec){}
    template<typename F , typename S>
    class iterator{

    private:
    F first_iterator; // It for the first "range"
    S second_iterator; // It for the second "range"
    bool first_It;  // check if the first It end to be able move correctly to second It
    public:

    iterator(F _first , S _sec):
        first_iterator(_first),second_iterator(_sec) , first_It(true)
    {}

    iterator& operator ++(){
    if(first_It){first_iterator++;} // if we have more values in the first It
    else {second_iterator++;}
    }

    bool operator !=(const chain::iterator<F,S>& o){ // in this operator function we can check if we cover all the first It
       if(!(first_iterator != o.first_iterator)){ // when we run on for loop e.g (iterator i = ... ; i != something.end ...) so if they equal its mens we can move to It2
          first_It = false;
       }
       if(first_It){return first_iterator != o.first_iterator;}
       else{return second_iterator != o.second_iterator;}
    }

    auto operator *(){
        if (first_It) // if we have more values in the first It
        {
            return *first_iterator;
        }
        else
        {
            return *second_iterator;
        }
        }

        };

    auto begin()const{
            return iterator<T,E>(first.begin(), sec.begin());
        }
    auto end()const{
            return iterator<T,E>(first.end(), sec.end());
        }


 };

}
