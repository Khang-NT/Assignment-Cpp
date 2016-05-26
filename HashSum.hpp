/*
 * FileIOHelper.hpp
 *
 *  Created on: May 25, 2016
 *      Author: khang
 */
#pragma once

#include <string>
using namespace std;

//Prime numbers
#define A 76963
#define B 86969

namespace Hash {
	unsigned hashSum(string s) {
		unsigned hashCode = 51;
		for	(int i = 0; i < s.length(); i++)
			hashCode = (hashCode * s.at(i)) ^ (s[0] * B);
		return hashCode;
	}

	bool checkHashCode(string s, unsigned code) {
		unsigned sHashCode = hashSum(s);
		return sHashCode == code;
	}
}
