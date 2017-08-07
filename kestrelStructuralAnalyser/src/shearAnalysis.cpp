/*
 * shearAnalysis.cpp
 *
 *  Created on: 04.08.2017
 *      Author: ACagatay
 */

#include "shearAnalysis.hpp"

shearAnalysis::shearAnalysis( double yieldStressBolt,
							  double yieldStressStruc,
							  double safetyFactor,
							  double boltNomDiameter,
							  double boltPitch):
							  myYieldStressBolt (yieldStressBolt),
							  myYieldStressStruc (yieldStressStruc),
							  mySafetyFactor (safetyFactor),
							  myTrescaShearCoeff (0.577),
							  pi(3.141592653589793238463),
							  myBoltNomDiameter (boltNomDiameter),
							  myBoltPitch (boltPitch)
{
	myBoltMinDiameter = myBoltNomDiameter - 1.226869*myBoltPitch;
	myBoltMinArea = 0.25*pi*pow(myBoltMinDiameter,2);
	myBoltNomArea = 0.25*pi*pow(myBoltNomDiameter,2);

	cout << "myBoltMinArea= " << myBoltMinArea << endl;
	cout << "myBoltNomArea= " << myBoltNomArea << endl;

	myShearYieldStressBolt = myTrescaShearCoeff*myYieldStressBolt;
	myShearYieldStressStruc = myTrescaShearCoeff*myYieldStressStruc;
}

shearAnalysis::~shearAnalysis()
{
	// TODO Auto-generated destructor stub
}

void shearAnalysis::calcShearInBolts( double criticalShearForce )
{
		myShearStressBolt = criticalShearForce / myBoltNomArea;

		if ( myShearStressBolt*mySafetyFactor < myShearYieldStressBolt)
		{
			cout << "The bolt passed shear analysis." << endl;
		}
		else
		{
			cout << "The bolt failed shear analysis." << endl;
		}

		cout << "myShearStressBolt= " << myShearStressBolt << endl;
}
