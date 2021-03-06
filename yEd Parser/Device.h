#ifndef Device_H
#define Device_H
#pragma once
#include "Node.h"
class Device : public Node {
private:
	string FindTrueID(string line);
	string FindDeviceID(string line);

	string device_id;
	string device_location;

public:
	Device(string line_one, string line_two);
	~Device();

	void SetLocation(string input);
	void SetNodeNum();

	string ReturnDeviceID();
	string ReturnDeviceLocation();
};

#endif