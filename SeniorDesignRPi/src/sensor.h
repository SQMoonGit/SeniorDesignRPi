/*
 * sensor.h
 *
 *  Created on: Feb 20, 2019
 *      Author: Hyunkyu
 */

#ifndef SENSOR_H_
#define SENSOR_H_

//Sensor class to support an array of sensors
class Sensor
{
private:
	//integer value of valve which ranges from -1 to 1
	//0 = closed, stop, -1 = open/lift down, 1 = open/lift up
	int valve;
	//double of height read from the sensor
	double height;
	//int value of status again ranging from -1 to 1
	//0 = stop, -1 = reset, 1 = good to lift
	int status;
public:
	//gets the height of the sensor
	double getHeight() const;
	//gets the status of the sensor
	int getStatus() const;
	//gets the valve value of the sensor
	int getValve() const;
	//changes status of the sensor with a new int value
	void changeStatus(int newStatus);
	//changes valve value with new int value
	void changeValve(int newValve);
	//changes height with new double value
	void changeHeight(double newHeight);

	Sensor(double, int, int);
	Sensor();
};
#endif /* SENSOR_H_ */
