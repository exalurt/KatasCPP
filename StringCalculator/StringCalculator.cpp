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

int CStringCalculator::calc(const string s)
{
	vector<int> elemens{ splitToInt(s) };
	int resultado { 0 };

	for each (int item in elemens)
	{
		resultado += item;
	}

	return resultado;
}