#include "stdafx.h"
#include "Node.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
using namespace std;

string Node::FindTrueID(string line) {
	string temp;

	if (line.find("node id=") != std::string::npos) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '\"') {
				int j = i + 1;

				while (line[j] != '\"') {
					temp.push_back(line[j]);
					j++;
				}
				break;
			}
		}
	}
	return temp;
}

string Node::FindNodeLabel(string line){
	string temp;

	if (line.find("y:NodeLabel") != std::string::npos) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '>') {
				int j = i + 1;

				while (line[j] != '<') {
					temp.push_back(line[j]);
					j++;
				}
				break;
			}
		}
	}

	return temp;
}

Node::Node(string line_one, string line_two){
	true_id = FindTrueID(line_one);
	nodenum = FindNodeLabel(line_two);
}

Node::Node() {

}

Node::~Node(){

}

void Node::SetAttributes(){}
void Node::SetNodeNum(){}
void Node::SetIPAddress(){}
void Node::SetDefault(string){}
void Node::SetLocation(string){}
void Node::SetZone(int){}
void Node::SetParent(string, string){}
void Node::SetStateChangeTime(){}
void Node::SetChildren(string){}
void Node::SetEverything(){}

string Node::PrintNodeNum() { return NULL; }
string Node::PrintIPAddress(){ return NULL; }
string Node::PrintDefault(){ return NULL; }
string Node::PrintLocation(){ return NULL; }
string Node::PrintZone(){ return NULL; }
string Node::PrintParentNodeNum(){ return NULL; }
string Node::PrintParentDistance(){ return NULL; }
string Node::PrintStateChangeTime(){ return NULL; }
string Node::PrintChildren(){ return NULL; }
string Node::PrintEverything(){ return NULL; }

string Node::ReturnNodeNum(){ return NULL; }
string Node::ReturnIPAddress(){ return NULL; }
string Node::ReturnDefault(){ return NULL; }
string Node::ReturnLocation(){ return NULL; }
string Node::ReturnLayer(){ return NULL; }
string Node::ReturnZone(){ return NULL; }
string Node::ReturnParentNodeNum(){ return NULL; }
string Node::ReturnParentDistance(){ return NULL; }
string Node::ReturnStateChangeTime(){ return NULL; }

vector<string> Node::ReturnChildren() { vector<string> temp; return temp; }

bool Node::ReturnHasParent() { return 0; }
bool Node::ReturnHasChildren(){ return 0; }
bool Node::ReturnHasLocation(){ return 0; }
bool Node::ReturnHasZone(){ return 0; }