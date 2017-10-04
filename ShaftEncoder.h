/*
 * ShaftEncoder.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Justin Eskesen
 */

#ifndef SHAFTENCODER_H_
#define SHAFTENCODER_H_

#include <Arduino.h>

// *****Quadrature Encoder*****
#include <QuadDecode.h>
class ShaftEncoder
{
public:
	ShaftEncoder();
	virtual ~ShaftEncoder(){}
	void init();
	float getVel();  // linear velocity
private:

	void read();
	QuadDecode<1> encoder;
	uint32_t prevSampleTimeUsec, currentSampleTimeUsec;
	int32_t prevTicks, currentTicks;
	float ticksPerMeter;
};

#endif /* SHAFTENCODER_H_ */
