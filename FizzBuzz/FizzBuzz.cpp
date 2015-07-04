// FizzBuzz.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FizzBuzz.h"


// This is an example of an exported variable
FIZZBUZZ_API int nFizzBuzz=0;

// This is an example of an exported function.
FIZZBUZZ_API int fnFizzBuzz(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see FizzBuzz.h for the class definition
CFizzBuzz::CFizzBuzz()
{
	return;
}
