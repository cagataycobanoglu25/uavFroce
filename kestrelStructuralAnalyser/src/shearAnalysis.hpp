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
				   double boltPitch);
	virtual ~shearAnalysis();

	void calcShearInBolts ( double criticalShearForce );
	void calcBearingStressInBolt ();
	void calcBearingStressInStruc();
	void calcBoltThreadExtShearPlane();
	void calcEdgeShearingInStruc();
	void calcTensileYieldigAccHolesInStruc();

	double myYieldStressBolt;
	double myYieldStressStruc;
	double mySafetyFactor;
	double myTrescaShearCoeff;

	const double pi;

	double myBoltNomDiameter;
	double myBoltPitch;

	double myBoltMinDiameter;
	double myBoltMinArea;
	double myBoltNomArea;

	double myShearYieldStressBolt;
	double myShearYieldStressStruc;
	double myShearStressBolt;





};

#endif /* SHEARANALYSIS_HPP_ */
