
#include <iostream>
#include <string>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;
#include"badkan.hpp"

template<typename Iterable>
string iterable_to_string(Iterable iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	return ostr.str();
}

int main(){

    badkan::TestCase testCase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        testCase.setname("Tests for Range:");
        testCase.CHECK_OUTPUT(iterable_to_string(range(1,4)),"1,2,3,");
        testCase.CHECK_OUTPUT(iterable_to_string(range(5,7)),"5,6,");
        testCase.CHECK_OUTPUT(iterable_to_string(range(1,5)),"1,2,3,4,");


        testCase.setname("Tests for Chain:");
        testCase.CHECK_OUTPUT(iterable_to_string(chain(range(1,4), range(5,8))),"1,2,3,5,6,7,");
        testCase.CHECK_OUTPUT(iterable_to_string(chain( range(5,8) ,range(8,9))),"5,6,7,8,");
        
        testCase.setname("Tests for Zip:");
        testCase.CHECK_OUTPUT(iterable_to_string(zip(range(1,6), string("hello"))),"1,h,2,e,3,l,4,l,5,o,");


        testCase.setname("Tests for Product:");
        testCase.CHECK_OUTPUT(iterable_to_string(product(range(1,4), string("hello"))),"1,h,1,e,1,l,1,l,1,o,2,h,2,e,2,l,2,l,2,o,3,h,3,e,3,l,3,l,3,o,");


        testCase.setname("Tests for Power-set:");
        testCase.CHECK_OUTPUT(iterable_to_string(powerset(range(1,4))),"{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}");
            grade = testCase.grade();
    }
    else {
        testCase.print_signal(signal);
        grade = 0;
    }
    cout << "grade is :" << grade << endl;

    return 0;

}

