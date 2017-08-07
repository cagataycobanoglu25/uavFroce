/*
 * staticForceCalculator.cpp
 *
 *  Created on: 07.08.2017
 *      Author: ACagatay
 */

#include "staticForceCalculator.hpp"

staticForceCalculator::staticForceCalculator(double frontThrust,
		  	  	  	  	  	  	  	  	  	 double backThrust,
		  	  	  	  	  	  	  	  	  	 double wingConnFrontPoint,
		  	  	  	  	  	  	  	  	  	 double wingConnBackPoint,
		  	  	  	  	  	  	  	  	  	 double frontTiltConnPoint,
		  	  	  	  	  	  	  	  	  	 double backTiltConnPoint,
		  	  	  	  	  	  	  	  	  	 double distBtwRotAxis):
		  myFrontThrust (frontThrust),
		  myBackThrust (backThrust),
		  myWingConnFrontPoint (wingConnFrontPoint),
		  myWingConnBackPoint (wingConnBackPoint),
		  myFrontTiltConnPoint (frontTiltConnPoint),
		  myBackTiltConnPoint (backTiltConnPoint),
		  myDistBtwRotAxis (distBtwRotAxis)
{
	// Calculation of Distance for Force & Moment Calculations
	myFrontTiltDist = myFrontTiltConnPoint;
	myBackTiltDist =  myDistBtwRotAxis - myBackTiltConnPoint;
	myFrontTiltMomArm = myWingConnFrontPoint - myFrontTiltConnPoint;
	myBackTiltMomArm = myBackTiltConnPoint - myWingConnFrontPoint;
	myDistBtwTwoWingConn = myWingConnBackPoint - myWingConnFrontPoint;

	cout << "myFrontTiltDist = "  << myFrontTiltDist << endl;
	cout << "myBackTiltDist = "  << myBackTiltDist << endl;
	cout << "myFrontTiltMomArm = "  << myFrontTiltMomArm << endl;
	cout << "myBackTiltMomArm = "  << myBackTiltMomArm << endl;
	cout << "myDistBtwTwoWingConn = "  << myDistBtwTwoWingConn << endl;

}

staticForceCalculator::~staticForceCalculator() {
	// TODO Auto-generated destructor stub
}

void staticForceCalculator::analyseBoltOnSidePlate( )
{
	calcForceOnMiddlePlate( );
}

void staticForceCalculator::calcForceOnMiddlePlate( )
{
	myMomentFrontTiltConn = myFrontThrust*myFrontTiltDist;
	myMomentBackTiltConn = myBackThrust*myBackTiltDist;

	cout << "myMomentFrontTiltConn=" << myMomentFrontTiltConn << endl;
	cout << "myMomentBackTiltConn=" << myMomentBackTiltConn << endl;


	myForceBackWingConn = (- myFrontThrust*myFrontTiltMomArm - myMomentFrontTiltConn + myBackThrust*myBackTiltMomArm + myMomentBackTiltConn) / myDistBtwTwoWingConn;

	myForceFrontWingConn = myFrontThrust + myBackThrust - myForceBackWingConn;

	cout << "myForceFrontWingConn=" << myForceFrontWingConn << endl;
	cout << "myForceBackWingConn=" << myForceBackWingConn << endl;



}

