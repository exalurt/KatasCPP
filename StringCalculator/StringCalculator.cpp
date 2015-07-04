// StringCalculator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "StringCalculator.h"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string subString(const string &s, const string &separator)
{
	std::string result = s;
	while (result.find(separator) != std::string::npos)
		result.replace(result.find(separator), separator.length(), ":");
	return result;
}

vector<string> getSeparators(const string &s)
{
	if (s[0] != '/')
		return vector<string> { ",", "\n" };
	return vector<string> { string{ s[2] } };
}

string getString(const string &s)
{
	if ('/' == s[0])
		return s.substr(4);
	return s;
}

string fixString(const string &s)
{
	string result = getString(s);
	vector<string> separators{ getSeparators(s) };

	for each (string separator in separators)
		result = subString(result, separator);

	return result;
}

vector<int> splitToInt(const string &s) {
	stringstream	ss{ fixString(s) };
	vector<int>		elems;
	string			item;

	while (getline(ss, item, ':')) {
		elems.push_back(atoi(item.c_str()));
	}

	return elems;
}

void throwError(const vector<int> &v)
{
	string error{ "Números negativos no soportados" };
	for each (int item in v)
	{
		if (0 > item)
			error += " " + item;
	}
	throw exception(error.c_str());
}

int CStringCalculator::calc(const string s)
{
	vector<int> elemens{ splitToInt(s) };
	int resultado { 0 };

	for each (int item in elemens)
	{
		if (1000 < item) continue;
		if (0 > item) throwError(elemens);
		resultado += item;
	}

	return resultado;
}