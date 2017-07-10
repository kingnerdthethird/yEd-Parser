#ifndef Pipe_H
#define Pipe_H
#pragma once
#include <iostream>
using namespace std;

class Pipe{
private:
	string source_id;
	string target_id;

	string source_nodenum;
	string target_nodenum;
	string length;

public:
	string FindSource(string);
	string FindTarget(string);
	string FindLength(string);

	Pipe(string, string);
	~Pipe();

	void SetSourceID(string);
	void SetTargetID(string);
	void SetSourceNodenum(string);
	void SetTargetNodenum(string);
	void SetLength(string);

	string ReturnSourceID();
	string ReturnTargetID();
	string ReturnSourceNodenum();
	string ReturnTargetNodenum();
	string ReturnLength();
};

#endif