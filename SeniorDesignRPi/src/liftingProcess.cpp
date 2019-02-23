/*
 * liftingProcess.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: Hyunkyu
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <array>
#include "sensor.h"
#include "liftingprocess.h"

using namespace std;

//array size will be passed in when class is called
double iterationStep[3];
double heightArray[3];
Sensor sensorArray[3];

//Changes all the sensor status to lift up
void liftingProcess::startStatus(Sensor *sensorArrai)
{
	for(int x=0; x< sensorArraySize; x++)
		sensorArrai[x].changeStatus(1);
}

//Changes all the sensor status to stop lift
void liftingProcess::stopStatus(Sensor *sensorArrai)
{
	for(int x=0; x< sensorArraySize; x++)
		sensorArrai[x].changeStatus(0);
}

//changes all valves to lift up
void liftingProcess::startAllPiers(Sensor *sensorArrai)
{
	for(int x=0; x< sensorArraySize; x++)
		sensorArrai[x].changeValve(1);
}

//Final height array calculation and assignment; returns pointer array to final height array
double * liftingProcess::finalHeight(Sensor *sensorArrai, int arraySize, double desiredHeight)
{
	static double finalHeightArray[arraySize];
	for(int x=0; x< arraySize; x++)
		finalHeightArray[x] = sensorArrai[x].getHeight() + desiredHeight;

	return finalHeightArray;
}

//Next height array calculation and assignment; returns pointer array to next height
double * liftingProcess::nextHeight(Sensor *sensorArrai, int arraySize, double stepArray[], int stepSize)
{
	double nextHeightArray[arraySize];
	for(int x=0; x< arraySize; x++)
		nextHeightArray[x] = sensorArrai[x].getHeight() + stepArray[stepSize];

	return nextHeightArray;
}

//Calculates the difference between the current height and step size height
//Returns an array with the differences
double * liftingProcess::compareHeights(double *nextHeightArray, double *currentHeight, int arraySize)
{
	double differenceHeight[arraySize];
	for(int x=0; x< arraySize; x++)
		differenceHeight[x] = nextHeightArray[x] - currentHeight[x];

	return differenceHeight;
}

//Checks the current height to the step height
void liftingProcess::checkHeights(Sensor *sensorArrai, double *nextHeight)
{
	counter =0;
	while(iterationDone == false)
	{
		for(int a=0; a< sensorArraySize; a++)
		{
			if(sensorArrai[a].getStatus() ==0)
				counter++;
			else if(sensorArrai[a].getHeight() == nextHeight[a])
			{
				sensorArrai[a].changeValve(0);
				sensorArrai[a].changeStatus(0);
				counter++;
			}
			if(counter == sensorArraySize)
				iterationDone = true;
		}
	}
}

//Determines the control for valves with the difference height array
//0 is determined as no need for height change
//1 is determined as height needs to be raised
//-1 is determined as height needs to be lowered
int * liftingProcess::controlHeight(double differenceHeight, int arraySize)
{
	int controlHeightArray[arraySize];
	for(int x=0; x<arraySize; x++)
	{
		if(differenceHeight[x] == 0)
			controlHeightArray[x] = 0;
		else if(differenceHeight[x] > 0 )
			controlHeightArray[x] = 1;
		else if(differenceHeight[x] < 0)
			controlHeightArray[x] = -1;
	}
	return controlHeightArray;
}


//Assigns passed sensor array with default sensors
void liftingProcess::defaultSensorArray(Sensor *sensorArrai)
{
	for(int x=0; x< sensorArraySize; x++)
	{
		Sensor n();
		sensorArrai[x] = n;
	}
}

//Basically assigns the initial height of the sensors
void liftingProcess::initialHeight(Sensor *sensorArrai)
{
	counter =0;
	while(counter < sensorArraySize)
	{
		sensorArrai[counter].changeHeight(sensorArrai[counter].getHeight());
		counter++;
	}
}


//Main lifting algorithm
Sensor * liftingProcess::liftingSlab(double stepIterations[], Sensor *sensorArrai[])
{
	startAllPiers(*sensorArrai);
	double *p, *s;
	int *j;

	for(int x =1; x<= iterationStepSize; x++)
	{
		iterationDone = false;
		counter =0;
		p = nextHeight();
		startAllPiers();
		//should be loop here encompassing the bottom 4 lines
		checkHeights();
		s = compareHeights();
		j = controlHeight();
		//need function here to change valve control based on controlHeight function return
	}



}


int main()
{
	finalHeight();
	defaultSensorArray();
	initalHeight();
	liftingSlab();

}



