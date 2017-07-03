#ifndef Node_H
#define Node_H
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
using namespace std;

class Node{
private:
	string FindTrueID(string);
	string FindNodeLabel(string);

protected:
	string name;
	string type;
	string true_id;
	string nodenum;
	string ip_address;
	string default_variable;
	string location;
	string layer;
	string zone;
	string parent_nodenum;
	string parent_distance;
	string state_change_time;

	vector<string> children;

	bool has_parent;
	bool has_children;
	bool has_location;
	bool has_zone;

public:
	Node(string, string);
	Node();
	~Node();

	void SetAttributes();
	void SetNodeNum();
	void SetIPAddress();
	void SetDefault(string);
	void SetLocation(string);
	void SetZone(int);
	void SetParent(string, string);
	void SetStateChangeTime();
	void SetChildren(string);
	void SetEverything();

	string PrintName();
	string PrintType();
	string PrintNodeNum();
	string PrintIPAddress();
	string PrintDefault();
	string PrintLocation();
	string PrintZone();
	string PrintParentNodeNum();
	string PrintParentDistance();
	string PrintStateChangeTime();
	string PrintChildren();
	string PrintEverything();

	string ReturnNodeNum();
	string ReturnIPAddress();
	string ReturnDefault();
	string ReturnLocation();
	string ReturnLayer();
	string ReturnZone();
	string ReturnParentNodeNum();
	string ReturnParentDistance();
	string ReturnStateChangeTime();

	vector<string> ReturnChildren();

	bool ReturnHasParent();
	bool ReturnHasChildren();
	bool ReturnHasLocation();
	bool ReturnHasZone();
};

#endif