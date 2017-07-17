#include "stdafx.h"
#include "Device.h"
#include <iostream>
#include <sstream>
using namespace std;

string Device::FindTrueID(string line) {
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

string Device::FindDeviceID(string line) {
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

Device::Device(string line_one, string line_two){
	InitializeProperties();

	true_id = FindTrueID(line_one);
	device_id = FindDeviceID(line_two);

	type = "STATION";

	SetNodeNum();

	SetEverything();
}


Device::~Device(){

}

void Device::SetNodeNum() {
	nodenum = device_id;
}