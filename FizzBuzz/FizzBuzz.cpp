// FizzBuzz.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FizzBuzz.h"
#include <string>
#include <vector>
#include "CodeNum.h"

using namespace std;

string CFizzBuzz::FizzBuzz(const int num)
{
	string result;
	vector<CCodeNum> list{
		{ 3, "Fizz" },
		{ 5, "Buzz" } };

	for (auto x : list)
		result += x.execute(num);

	return result.empty() ? to_string(num) : result;
}