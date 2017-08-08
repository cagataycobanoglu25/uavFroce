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
							  double boltPitch,
							  double strucThickness,
							  double edgeShearLength,
							  double restWidthInStruc):
							  myYieldStressBolt (yieldStressBolt),
							  myYieldStressStruc (yieldStressStruc),
							  mySafetyFactor (safetyFactor),
							  myTrescaShearCoeff (0.577),
							  pi(3.141592653589793238463),
							  myBoltNomDiameter (boltNomDiameter),
							  myBoltPitch (boltPitch),
							  myStrucThickness (strucThickness),
							  myEdgeShearLength (edgeShearLength),
							  myRestWidthInStruc (restWidthInStruc)
{
	myBoltMinDiameter = myBoltNomDiameter - 1.226869*myBoltPitch;
	myBoltMinArea = 0.25*pi*pow(myBoltMinDiameter,2);
	myBoltNomArea = 0.25*pi*pow(myBoltNomDiameter,2);

	myBoltBearingArea = myStrucThickness * myBoltNomDiameter;
	myEdgeShearArea = 2.0*myStrucThickness*myEdgeShearLength;

	myTensileStressArea = myRestWidthInStruc * myStrucThickness;

	cout << "myBoltMinArea= " << myBoltMinArea << endl;
	cout << "myBoltNomArea= " << myBoltNomArea << endl;
	cout << "myBoltBearingArea= " << myBoltBearingArea << endl;
	cout << "myEdgeShearArea= " << myEdgeShearArea << endl;
	cout << "myTensileStressArea= " << myTensileStressArea << endl;



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

void shearAnalysis::calcBearingStressInBolt( double criticalShearForce )
{
	myBearingStressBolt = criticalShearForce / myBoltBearingArea;

	if ( myBearingStressBolt*mySafetyFactor < myYieldStressBolt)
	{
		cout << "The bolt passed bearing analysis." << endl;
	}
	else
	{
		cout << "The bolt failed bearing analysis." << endl;
	}

	cout << "myBearingStressBolt= " << myBearingStressBolt << endl;

}

void shearAnalysis::calcBearingStressInStruc( double criticalShearForce)
{
	myBearingStressStruc = criticalShearForce / myBoltBearingArea;

	if ( myBearingStressStruc*mySafetyFactor < myYieldStressStruc)
	{
		cout << "The structure passed bearing analysis." << endl;
	}
	else
	{
		cout << "The structure failed bearing analysis." << endl;
	}

	cout << "myBearingStressStruc= " << myBearingStressStruc << endl;

}

void shearAnalysis::calcBoltThreadExtShearPlane(double criticalShearForce)
{
	myShearStressBolt = criticalShearForce / myBoltMinArea;

	if ( myShearStressBolt*mySafetyFactor < myShearYieldStressBolt)
	{
		cout << "The structure passed thread extended shear plane analysis." << endl;
	}
	else
	{
		cout << "The structure failed thread extended shear plane analysis." << endl;
	}

	cout << "myShearStressBolt= " << myShearStressBolt << endl;

}

void shearAnalysis::calcEdgeShearingInStruc( double criticalShearForce )
{
	myEdgeShearStressStruc = criticalShearForce / myEdgeShearArea;

	if ( myEdgeShearStressStruc*mySafetyFactor < myShearYieldStressStruc)
	{
		cout << "The structure passed edge shear  analysis." << endl;
	}
	else
	{
		cout << "The structure failed edge shear analysis." << endl;
	}

	cout << "myEdgeShearStressStruc= " << myEdgeShearStressStruc << endl;

}

void shearAnalysis::calcTensileYieldigAccHolesInStruc( double criticalShearForce )
{
	myTensileStressAtHoleStruc = criticalShearForce/myTensileStressArea;

	if ( myTensileStressAtHoleStruc*mySafetyFactor < myYieldStressStruc)
	{
		cout << "The structure passed tensile stress analysis at hole position." << endl;
	}
	else
	{
		cout << "The structure failed tensile stress analysis at hole position." << endl;
	}

	cout << "myTensileStressAtHoleStruc= " << myTensileStressAtHoleStruc << endl;

}


