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

void Node::SetAttributes(){
	//I don't think this is needed.
}

void Node::SetNodeNum(){
	nodenum = "0";
}

void Node::SetIPAddress(){
	ip_address = "0.0.0.0";
}

void Node::SetDefault(string){}
void Node::SetLocation(string){
	has_location = true;
	location = "Default";
}

void Node::SetZone(int){}
void Node::SetParent(string, string){}
void Node::SetStateChangeTime(){}
void Node::SetChildren(string){}
void Node::SetEverything(){}

string Node::PrintName() {
	return "\t\t<NAME>" + name + "</NAME>\n";
}

string Node::PrintType() {
	return "\t\t<TYPE>" + type + "</TYPE>\n";
}

string Node::PrintNodeNum() {
	return "\t\t<NODENUM>" + nodenum + "</NODENUM>\n";
}

string Node::PrintIPAddress(){
	return "\t\t<IPADDR>" + ip_address + "</IPADDR>\n";
}

string Node::PrintDefault(){ 
	if (nodenum.compare(default_variable) == 0) {
		return "\t\t<DEFAULT>" + default_variable + "</DEFAULT>\n";
	}

	else {
		return "";
	}
}

string Node::PrintLocation(){
	if (has_location) {
		return "\t\t<LOCATION>" + location + "</LOCATION>\n";
	}

	else {
		return "";
	}
}

string Node::PrintZone(){
	if (has_zone) {
		return "\t\t<ZONE>" + zone + "</ZONE>\n";
	}

	else {
		return "";
	}
}

string Node::PrintParentNodeNum(){
	if (has_parent) {
		return "\t\t<PARENT>" + parent_nodenum + "</PARENT>\n";
	}

	else {
		return "";
	}
}

string Node::PrintParentDistance(){
	if (has_parent) {
		return "\t\t<DISTANCE>" + parent_distance + "</PARENT>\n";
	}

	else {
		return "";
	}
}

string Node::PrintStateChangeTime(){
	return "\t\t<STATECHANGETIME>" + state_change_time + "</STATECHANGETIME>\n";
}

string Node::PrintChildren(){
	string output;
	if (has_children) {
		for (int i = 0; i < children.size(); i++) {
			stringstream converter;
			string portnum;
			converter << i + 1;
			portnum = converter.str();

			output += "\t\t<CHILDREN>\n";
			output += "\t\t\t<NODENUM>";
			output += children[i];
			output += "</NODENUM>\n";
			output += "\t\t\t<PORTNUM>";
			output += portnum;
			output += "</PORTNUM>\n";
			output += "\t\t</CHILDREN>\n";
		}

		return output;
	}

	else {
		return "";
	}
}

string Node::PrintEverything(){
	string output;

	output += "\t<NODE>\n";
	output += PrintName();
	output += PrintDefault();
	output += PrintNodeNum();
	output += PrintIPAddress();
	output += PrintLocation();
	output += PrintType();
	output += PrintZone();
	output += PrintParentNodeNum();
	output += PrintParentDistance();
	output += PrintStateChangeTime();
	output += PrintChildren();
	output += "\t</NODE>\n";

	return output;
}

string Node::ReturnNodeNum(){
	return nodenum; 
}

string Node::ReturnIPAddress() { 
	return ip_address;
}

string Node::ReturnDefault(){ 
	return default_variable;
}

string Node::ReturnLocation(){ 
	return location;
}

string Node::ReturnLayer(){ 
	return layer;
}

string Node::ReturnZone(){ 
	return zone;
}

string Node::ReturnParentNodeNum(){ 
	return parent_nodenum;
}

string Node::ReturnParentDistance(){ 
	return parent_distance;
}

string Node::ReturnStateChangeTime(){ 
	return state_change_time;
}

vector<string> Node::ReturnChildren() { 
	vector<string> temp; return temp;
}

bool Node::ReturnHasParent() { 
	return has_parent;
}

bool Node::ReturnHasChildren(){ 
	return has_children;
}

bool Node::ReturnHasLocation(){ 
	return has_location;
}

bool Node::ReturnHasZone(){ 
	return has_zone;
}