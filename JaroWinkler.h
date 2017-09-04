#ifndef JAROWINKLER_H
#define JAROWINKLER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class JaroObj {
public:
	JaroObj() {}
	~JaroObj() {}
	const double WeightStringA = 1.0/3.0;
	const double WeightStringB = 1.0/3.0;
	const double WeightTranpose = 1.0/3.0;
	const double ScalingFac = 0.0;//0.1
	const double BoostThreshold = 0.0;//0.7
	const unsigned long int PrefizSize = 4;

	double jaroDistance(const std::string& a, const std::string& b);
	double jaroWinklerDistance(const std::string&a, const std::string& b);
};



#endif