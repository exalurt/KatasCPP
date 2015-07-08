// FizzBuzz.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FizzBuzz.h"
#include <string>
using namespace std;

bool contain(string value, int num)
{
	return string::npos != to_string(num).find(value);
}

bool isDivisible(int divisor, int num)
{
	return (0 == num % divisor);
}

bool isBuzz(int num)
{
	return isDivisible(5, num) || contain("5", num);
}

bool isFizz(int num)
{
	return isDivisible(3, num) || contain("3", num);
}

string Fizz(const int num)
{
	if (isFizz(num))
		return string{ "Fizz" };
	return "";
}

string Buzz(const int num)
{
	if (isBuzz(num))
		return string{ "Buzz" };
	return "";
}

string CFizzBuzz::FizzBuzz(const int num)
{
	string result = Fizz(num) + Buzz(num);

	return result.empty() ? to_string(num) : result;
}