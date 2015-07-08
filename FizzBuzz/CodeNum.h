#pragma once

#include <string>
using namespace std;

class CCodeNum{
	int num;
	std::string value;

	bool contain(const int num)
	{
		return std::string::npos != to_string(num).find(to_string(this->num));
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
	CCodeNum(int num, std::string value) : num{ num }
	{
		this->value = value;
	};

	string execute(const int num)
	{
		if (is(num))
			return value;
		return "";
	};
};