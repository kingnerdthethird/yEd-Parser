#include "stdafx.h"
#include "LinearCoupler.h"


LinearCoupler::LinearCoupler(){
	InitializeProperties();

	nodenum = "Linear Coupler";
	true_id = "n4";

	SetEverything();

}


LinearCoupler::~LinearCoupler(){

}
