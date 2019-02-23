/*
 * liftingprocess.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Hyunkyu
 */

#ifndef LIFTINGPROCESS_H_
#define LIFTINGPROCESS_H_

class liftingProcess
{
private:
	int iterationStepSize, heightArraySize, sensorArraySize;
	int counter =0;
	bool iterationDone = false;
public:
	void liftingProcess::startStatus(Sensor *sensorArrai);
	void liftingProcess::stopStatus(Sensor *sensorArrai);
	void liftingProcess::startAllPiers(Sensor *sensorArrai);
	double *liftingProcess::finalHeight(Sensor *sensorArrai, int arraySize, double desiredHeight);
	double *liftingProcess::nextHeight(Sensor *sensorArrai, int arraySize, double stepArray[], int stepSize);
	double *liftingProcess::compareHeights(double *nextHeightArray, double *currentHeight, int arraySize);
	void liftingProcess::checkHeights(Sensor *sensorArrai, double *nextHeightArray);
	int *liftingProcess::controlHeight(double differenceHeight, int arraySize);
	void liftingProcess::defaultSensorArray(Sensor *sensorArrai);
	void liftingProcess::initialHeight(Sensor *sensorArrai);
	Sensor *liftingProcess::liftingSlab(double stepIterations[], Sensor *sensorArrai[])
};



#endif /* LIFTINGPROCESS_H_ */
