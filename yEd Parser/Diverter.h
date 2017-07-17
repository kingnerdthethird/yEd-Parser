#pragma once
#include "Node.h"
class Diverter : public Node {
private:
	string FindTrueID(string);
	string FindDiverterID(string);

	string diverter_id;
	string diverter_location;

public:
	Diverter(string, string);
	~Diverter();

	void SetNodeNum();

	string ReturnDiverterID();
	string ReturnDiverterLocation();
};

