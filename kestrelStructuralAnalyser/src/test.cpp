//============================================================================
// Name        : fastenerAnalyser.cpp
// Author      : Cagatay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "staticForceCalculator.hpp"


#include <iostream>

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	double criticalForceOnBolt;
	double frontThrust = 50;
	double backThrust = 50;

	double wingConnFrontPoint= 176.58 ;
	double wingConnBackPoint= 386.33;
	double frontTiltConnPoint=  110.44;
	double backTiltConnPoint= 467.93;
	double distBtwRotAxis= 578.37;

	staticForceCalculator forceOnSidePlate( frontThrust, backThrust,
											wingConnFrontPoint, wingConnBackPoint,
											frontTiltConnPoint, backTiltConnPoint,
											distBtwRotAxis);

	forceOnSidePlate.calcForceOnMiddlePlate( );

	if (forceOnSidePlate.myForceBackWingConn > forceOnSidePlate.myForceFrontWingConn)
	{
		criticalForceOnBolt = forceOnSidePlate.myForceBackWingConn;
	}
	else
	{
		criticalForceOnBolt = forceOnSidePlate.myForceFrontWingConn;
	}



	return 0;
}
