//============================================================================
// Name        : 11_exceptions_assertions.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>  
#include <string>
using namespace std;

//if following symbol not defined then assertions are compiled in
//if it is defined then they are optimized away to nothing
//IT MUST BE DEFINED BEFORE YOU INCLUDE <assert>
#define NDEBUG 
#include <assert.h>     /* assert */

void test_assert(int* myInt) {
	//if argument evaluates to false and;  
	//debug mode   - NDEBUG is undefined  - the assertion fires, prints file and line
	//release mode - NDEBUG is not defined- the assertion is conditionally compiled to nothing
	//try both by (un)commenting 3define NDEBUG above
	assert (myInt!=NULL);
	cout<<"%d\n"<<*myInt<<endl;
}


int main()
{
	//assertion
	int * c = NULL;
//	test_assert (c);
	
	//test some try/catch	
	int x=1;
	int y=0;
	try
	{
		if (y==0)
			throw x;
		cout<<"x/y is "<<x/y<<endl;
	}
	catch(int &num){
		
		cout<<"Div by 0 error when x="<<x<<endl;
	}
	
	//test bad alloc (try to alloc too much)
	const int SIXTEEN_GIG = 4000000000;	//4bytes*4000000000
	try
	{
		int *y= new int[SIXTEEN_GIG];
		cout<<"allocated a bunch of memory"<<endl;
	}
	catch(bad_alloc &ba){
		
		cout<<"memory alloc error"<<endl;
	}

	return 0;
}
