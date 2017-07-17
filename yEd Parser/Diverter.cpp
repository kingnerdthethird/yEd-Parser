#include "stdafx.h"
#include "Diverter.h"
#include <iostream>
#include <sstream>
using namespace std;

string Diverter::FindTrueID(string line) {
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

string Diverter::FindDiverterID(string line) {
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

Diverter::Diverter(string line_one, string line_two){
	InitializeProperties();

	true_id = FindTrueID(line_one);
	diverter_id = FindDiverterID(line_two);

	type = "DIVERTER";

	SetNodeNum();

	SetEverything();
}

Diverter::~Diverter(){

}

void Diverter::SetNodeNum() {
	nodenum = diverter_id;
}

string Diverter::ReturnDiverterID() {
	return diverter_id;
}

string Diverter::ReturnDiverterLocation() {
	return diverter_location;
}