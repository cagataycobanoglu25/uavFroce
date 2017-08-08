/*
 * shearAnalysis.hpp
 *
 *  Created on: 04.08.2017
 *      Author: ACagatay
 */

#ifndef SHEARANALYSIS_HPP_
#define SHEARANALYSIS_HPP_

#include <iostream>
#include <math.h>

using namespace std;

class shearAnalysis {
public:
	shearAnalysis( double yieldStressBolt,
				   double yieldStressStruc,
				   double safetyFactor,
				   double boltNomDiameter,
				   double boltPitch,
				   double strucThickness,
				   double edgeShearLength,
				   double restWidthInStruc);

	virtual ~shearAnalysis();

	void calcShearInBolts ( double criticalShearForce );
	void calcBearingStressInBolt ( double criticalShearForce );
	void calcBearingStressInStruc( double criticalShearForce );
	void calcBoltThreadExtShearPlane(double criticalShearForce);
	void calcEdgeShearingInStruc(double criticalShearForce);
	void calcTensileYieldigAccHolesInStruc(double criticalShearForce);

	double myYieldStressBolt;
	double myYieldStressStruc;
	double mySafetyFactor;
	double myTrescaShearCoeff;

	const double pi;

	double myBoltNomDiameter;
	double myBoltPitch;
	double myStrucThickness;
	double myEdgeShearLength;
	double myRestWidthInStruc;

	double myBoltMinDiameter;
	double myBoltMinArea;
	double myBoltNomArea;
	double myBoltBearingArea;
	double myEdgeShearArea;
	double myTensileStressArea;

	double myShearYieldStressBolt;
	double myShearYieldStressStruc;
	double myShearStressBolt;
	double myBearingStressBolt;
	double myBearingStressStruc;
	double myEdgeShearStressStruc;
	double myTensileStressAtHoleStruc;





};

#endif /* SHEARANALYSIS_HPP_ */
