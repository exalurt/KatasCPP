// StringCalculator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "StringCalculator.h"

#include <string>
#include <vector>
#include <sstream>

std::vector<int> CStringCalculator::splitToInt(const std::string &s) {
	std::vector<int> elems;
	std::stringstream ss { s };
	std::string item;
	while (std::getline(ss, item, ',')) {
		elems.push_back(atoi(item.c_str()));
	}
	return elems;
}

int CStringCalculator::calc(const std::string s)
{
	std::vector<int> x{ splitToInt(s) };
	int resultado { 0 };
	for (int item : x)
		resultado += item;

	return resultado;
}