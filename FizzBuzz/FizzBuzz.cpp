// FizzBuzz.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FizzBuzz.h"
#include <string>
using namespace std;

string divisible3(const int num)
{
	if (0 == num % 3 || string::npos != to_string(num).find("3"))
		return string{ "Fizz" };
	return "";
}

string divisible5(const int num)
{
	if (0 == num % 5 || string::npos != to_string(num).find("5"))
		return string{ "Buzz" };
	return "";
}

string CFizzBuzz::FizzBuzz(const int num)
{
	string result = divisible3(num) + divisible5(num);

	return (0 != result.length() ? result : to_string(num));
}