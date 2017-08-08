//============================================================================
// Name        : fastenerAnalyser.cpp
// Author      : Cagatay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "staticForceCalculator.hpp"
#include "shearAnalysis.hpp"


#include <iostream>

using namespace std;

int main() {

	double criticalForceOnBolt;
	double frontThrust = 50;
	double backThrust = 50;

	double wingConnFrontPoint= 176.58 ;
	double wingConnBackPoint= 386.33;
	double frontTiltConnPoint=  110.44;
	double backTiltConnPoint= 467.93;
	double distBtwRotAxis= 578.37;

	double yieldStressM3CSK = 210;
	double yieldStressAlu = 150;
	double safetyFactor = 3.0;

	double boltNomDiameter = 3.0;
	double boltPitch = 0.5;



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

	shearAnalysis shearAnalyser ( yieldStressM3CSK, yieldStressAlu,
								  safetyFactor, boltNomDiameter, boltPitch );

	shearAnalyser.calcShearInBolts( criticalForceOnBolt );


	return 0;
}
