/*
 * Sensor.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: Hyunkyu
 */

#include <iostream>
#include <string>
#include "sensor.h"

double Sensor::getHeight() const
{
	return height;
}

int Sensor::getStatus() const
{
	return status;
}

int Sensor::getValve() const
{
	return valve;
}

void Sensor::changeStatus(int newStatus)
{
	status = newStatus;
}

void Sensor::changeHeight(double newHeight)
{
	height = newHeight;
}

void Sensor::changeValve(int newValve)
{
	valve = newValve;
}

Sensor::Sensor(double heightV, int statusV, int valveV)
{
	height = heightV;
	status = statusV;
	valve = valveV;
}

Sensor::Sensor()
{
	height = 0;
	valve = 0;
	status = 0;
}


