/*
 * staticForceCalculator.hpp
 *
 *  Created on: 07.08.2017
 *      Author: ACagatay
 */

#ifndef STATICFORCECALCULATOR_HPP_
#define STATICFORCECALCULATOR_HPP_

#include <math.h>
#include <iostream>

using namespace std;

class staticForceCalculator {
public:
	staticForceCalculator(double frontThrust,
						  double backThrust,
						  double wingConnFrontPoint,
						  double wingConnBackPoint,
						  double frontTiltConnPoint,
						  double backTiltConnPoint,
						  double distBtwTwoRotAxis);

	virtual ~staticForceCalculator();

	void analyseBoltOnSidePlate( );

// ===== FORCE VARIABLES =====
	double myFrontThrust;
	double myBackThrust;
	double myForceFrontWingConn;
	double myForceBackWingConn;


// ===== MOMENT VARIABLES =====

	double myMomentFrontTiltConn;
	double myMomentBackTiltConn;

// ===== POSITION VARIABLES =====
//	reltive distances to front rotation axis
	double myWingConnFrontPoint;
	double myWingConnBackPoint;
	double myFrontTiltConnPoint;
	double myBackTiltConnPoint;
	double myDistBtwRotAxis;

	double myFrontTiltDist;
	double myBackTiltDist;
	double myFrontTiltMomArm;
	double myBackTiltMomArm;
	double myDistBtwTwoWingConn;


	void calcForceOnMiddlePlate( );




};

#endif /* STATICFORCECALCULATOR_HPP_ */
