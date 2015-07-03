// StringCalculator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "StringCalculator.h"


// This is an example of an exported variable
STRINGCALCULATOR_API int nStringCalculator=0;

// This is an example of an exported function.
STRINGCALCULATOR_API int fnStringCalculator(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see StringCalculator.h for the class definition
CStringCalculator::CStringCalculator()
{
	return;
}

int CStringCalculator::calc(std::string)
{
	return 0;
}