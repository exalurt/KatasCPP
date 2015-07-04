// StringCalculator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "StringCalculator.h"

#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <iostream>

using namespace std;

vector<int> CStringCalculator::splitToInt(const string &s) {
	regex			expr{ STRING_REGEX };
	stringstream	ss{ regex_replace(s, expr, ":") };
	vector<int>		elems;
	string			item;

	while (getline(ss, item, ':')) {
		elems.push_back(atoi(item.c_str()));
	}

	return elems;
}

void CStringCalculator::throwError(const vector<int> &v)
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