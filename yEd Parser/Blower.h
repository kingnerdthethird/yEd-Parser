#ifndef Blower_H
#define Blower_H
#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
using namespace std;

class Blower : public Node {
private:
	string FindTrueID(string);
	string FindZoneName(string);

	string blower_id;

public:
	Blower(string line_one, string line_two);
	~Blower();
};

#endif