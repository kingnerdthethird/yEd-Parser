#include "stdafx.h"
#include "Pipe.h"
#include <iostream>
#include <sstream>
using namespace std;

string Pipe::FindSource(string input) {
	string temp;

	if (input.find("source=") != std::string::npos) {
		int start = input.find("source=");
		for (int i = start; i < input.length(); i++) {
			if (input[i] == '\"') {
				int j = i + 1;

				while (input[j] != '\"') {
					temp.push_back(input[j]);
					j++;
				}
				break;
			}
		}
	}

	return temp;
}

string Pipe::FindTarget(string input) {
	string temp;

	if (input.find("target=") != std::string::npos) {
		int start = input.find("target=");
		for (int i = start; i < input.length(); i++) {
			if (input[i] == '\"') {
				int j = i + 1;

				while (input[j] != '\"') {
					temp.push_back(input[j]);
					j++;
				}
				break;
			}
		}
	}

	return temp;
}

string Pipe::FindLength(string line) {
	string temp;

	if (line.find("y:EdgeLabel") != std::string::npos) {
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

Pipe::Pipe(string edge_id, string edge_label){
	SetSourceID(FindSource(edge_id));
	SetTargetID(FindTarget(edge_id));
	SetLength(FindLength(edge_label));

	cout << source_id << endl;
	cout << target_id << endl;
	cout << length << endl;
}

Pipe::~Pipe(){

}

void Pipe::SetSourceNodenum(string input) {
	source_nodenum = input;
}

void Pipe::SetTargetNodenum(string input) {
	target_nodenum = input;
}

void Pipe::SetSourceID(string input) {
	source_id = input;
}

void Pipe::SetTargetID(string input) {
	target_id = input;
}

void Pipe::SetLength(string input) {
	length = input;
}

string Pipe::ReturnSourceID() {
	return source_id;
}

string Pipe::ReturnTargetID() {
	return target_id;
}

string Pipe::ReturnSourceNodenum() {
	return source_nodenum;
}

string Pipe::ReturnTargetNodenum() {
	return target_nodenum;
}

string Pipe::ReturnLength() {
	return length;
}