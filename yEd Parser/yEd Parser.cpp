#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
#include "Node.h"
#include "Blower.h"
#include "Device.h"
#include "Diverter.h"
#include "Pipe.h"
#include "LinearCoupler.h"
using namespace std;

ifstream file;
ofstream output;

bool CheckLine(string line);

void CreateNewGroup(string true_id, string label);
void CreateNewStation(string true_id, string label);
void CreateNewDiverter(string true_id, string label);
void CreateNewLab(string true_id, string label);
void CreateNewLinearCoupler(string true_id, string label);
void CreateNewPipe(string true_id, string label);

vector<Node *> master_node_list;
vector<Pipe *> master_pipe_list;

void FindZones();
void FindParents();
void FindChildren();

void SetUpFile();
void EndFile();

int main(){
	time_t now = time(0);
	char * dt = ctime(&now);
	tm * gmtm = gmtime(&now);
	dt = asctime(gmtm);


	file.open("Calgary Cancer Center.graphml");
	stringstream converter;
	converter << dt;
	string temp_name = converter.str();
	for (int i = 0; i < temp_name.length(); i++) {
		if (temp_name[i] == '\n') {
			temp_name.erase(i);
		}
		if (temp_name[i] == ':') {
			temp_name[i] = ' ';
		}
	}
	string output_name = "output " + temp_name + ".xml";
	output.open(output_name);

	cout << output_name << endl;

	vector<string> important_details;

	while (file.good()) {
		string temp;
		getline(file, temp);
		if (CheckLine(temp)){
			important_details.push_back(temp);
		}
	}

	for (int i = 0; i < important_details.size(); i++) {
		if (important_details[i].find("node id=") != std::string::npos) {
			if (important_details[i].find("\"group\"") != std::string::npos) {
				if (important_details[i + 1].find("y:NodeLabel") != std::string::npos) {
					CreateNewGroup(important_details[i], important_details[i + 1]);
				}
			}

			else {
				if (important_details[i + 1].find("data key=\"d5\"")!= std::string::npos) {
					if (important_details[i + 2].find("y:NodeLabel") != std::string::npos) {
						if (important_details[i + 1].find("[Station]") != std::string::npos) {
							CreateNewStation(important_details[i], important_details[i + 2]);
						}
						else if (important_details[i + 1].find("[Diverter]") != std::string::npos) {
							CreateNewDiverter(important_details[i], important_details[i + 2]);
						}
						else if (important_details[i + 1].find("[Lab]") != std::string::npos) {
							CreateNewLab(important_details[i], important_details[i + 2]);
						}
						else if (important_details[i + 1].find("[Linear Coupler]") != std::string::npos) {
							CreateNewLinearCoupler(important_details[i], important_details[i + 2]);
						}
					}
				}
			}
		}
		else if (important_details[i].find("edge id=") != std::string::npos) {
			if (important_details[i + 1].find("y:EdgeLabel") != std::string::npos) {
				CreateNewPipe(important_details[i], important_details[i + 1]);
			}
		}
	}

	output.close();
	file.close();
	system("PAUSE");
    return 0;
}

bool CheckLine(string line) {
	bool exists;

	exists = line.find("<node id=\"") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("\"group\"") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("<y:NodeLabel ") != string::npos && line.find("Folder") == string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("<data key=\"d5\"") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("[Station]") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("[Diverter]") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("[Lab]") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("[Linear Coupler]") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("<edge id=") != string::npos;
	if (exists) {
		return true;
	}

	exists = line.find("<y:EdgeLabel ") != string::npos;
	if (exists) {
		return true;
	}

	else {
		return false;
	}
}

void CreateNewGroup(string true_id, string label) {
	Blower * temp_blower;
	temp_blower = new Blower(true_id, label);
	master_node_list.push_back(temp_blower);
}

void CreateNewStation(string true_id, string label){}
void CreateNewDiverter(string true_id, string label){}
void CreateNewLab(string true_id, string label){}
void CreateNewLinearCoupler(string true_id, string label){}
void CreateNewPipe(string true_id, string label){}

void FindParents(){}
void FindChildren(){}

void SetUpFile(){
	if (output.is_open()) {
		output << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		output << "<CONFIG>" << endl;
		output << "\t<STATIONNODENUM>" << 0 << "</STATIONNODENUM>" << endl;
		output << "\t<VELOCITY>" << 0 << "</VELOCITY>" << endl;
		output << "\t<TIMESCALE>" << 0 << "</TIMESCALE>" << endl;
		output << "\t<NODE>" << endl;
		output << "\t\t<NAME>Master</NAME>" << endl;
		output << "\t\t<NODENUM>0</NODENUM>" << endl;
		output << "\t\t<IPADDR>0.0.0.0</IPADDR>" << endl;
		output << "\t\t<LOCATION>Master</LOCATION>" << endl;
		output << "\t\t<ZONE>0</ZONE>" << endl;
		output << "\t\t<PARENT>0</PARENT>" << endl;
		output << "\t</NODE>" << endl;
	}
}
void EndFile(){}