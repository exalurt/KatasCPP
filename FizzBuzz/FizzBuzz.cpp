// FizzBuzz.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FizzBuzz.h"
#include <string>
#include <vector>

using namespace std;

class CodeNum{
	int num;
	string value;

	bool contain(const int num)
	{
		return string::npos != to_string(num).find(to_string(this->num));
	};

	bool isDivisible(const int num)
	{
		return (0 == num % this->num);
	};

	bool is(const int num)
	{
		return isDivisible(num) || contain(num);
	};

public:
	CodeNum(int num, string value)
	{
		this->num = num;
		this->value = value;
	};

	string execute(const int num)
	{
		if (is(num))
			return value;
		return "";
	};
};

string CFizzBuzz::FizzBuzz(const int num)
{
	string result;
	vector<CodeNum> list{
		{ 3, "Fizz" },
		{ 5, "Buzz" } };

	for (auto x : list)
		result += x.execute(num);

	return result.empty() ? to_string(num) : result;
}