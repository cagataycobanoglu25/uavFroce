/*
 * shearAnalysis.hpp
 *
 *  Created on: 04.08.2017
 *      Author: ACagatay
 */

#ifndef SHEARANALYSIS_HPP_
#define SHEARANALYSIS_HPP_

class shearAnalysis {
public:
	shearAnalysis();
	virtual ~shearAnalysis();

	void calcShearInBolts ();
	void calcBearingStressInBolt ();
	void calcBearingStressInStruc();
	void calcBoltThreadExtShearPlane();
	void calcEdgeShearingInStruc();
	void calcTensileYieldigAccHolesInStruc();


};

#endif /* SHEARANALYSIS_HPP_ */
