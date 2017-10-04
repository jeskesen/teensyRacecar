/*
 * ShaftEncoder.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Justin Eskesen
 */

#include "ShaftEncoder.h"

ShaftEncoder::ShaftEncoder()
{
	ticksPerMeter = 1.0;

}

void ShaftEncoder::init()
{
	encoder.setup();
	encoder.start();
	encoder.zeroFTM();

	read();
}

float ShaftEncoder::getVel()
{
	read();
	return (float)(currentTicks-prevTicks)/((currentSampleTimeUsec-prevSampleTimeUsec)*ticksPerMeter);
}

void ShaftEncoder::read()
{
	prevSampleTimeUsec = currentSampleTimeUsec;
	currentSampleTimeUsec = micros();
	prevTicks = currentTicks;
    currentTicks = encoder.calcPosn();

}

