#include "stdafx.h"
#include "Blower.h"

string Blower::FindTrueID(string line) {
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

string Blower::FindZoneName(string line) {
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

Blower::Blower(string line_one, string line_two){
	InitializeProperties();

	true_id = FindTrueID(line_one);
	blower_id = FindZoneName(line_two);
	type = "BLOWER";

	SetZone();
	SetNodeNum();
	SetName();

	SetEverything();
}

Blower::~Blower(){

}

void Blower::SetNodeNum() {
	nodenum = zone + "00";
}

void Blower::SetZone() {
	string temp = blower_id;
	has_zone = true;

	if (temp.find("Zone ") != std::string::npos) {
		temp.erase(temp.find("Zone "), 5);
	}

	zone = temp;
}

void Blower::SetName() {
	name = "Blower " + nodenum;
}

string Blower::ReturnBlowerID() {
	return blower_id;
}