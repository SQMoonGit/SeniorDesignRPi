/*
 * SerialConnections.h
 *
 *  Created on: Jan 29, 2019
 *      Author: Hyunkyu
 */

#ifndef SERIALCONNECTIONS_H_
#define SERIALCONNECTIONS_H_

class SerialConnections
{
private:
	bool sensor;
	bool arduinos;
	bool power;
	bool gnd;
	bool internet;
	bool GCP;
public:
	void checkSensor();
	void checkArduinos();
	void checkPower();
	void checkGND();
	void checkInternet();
	void checkGCP();
	SerialConnections();
	~SerialConnections();
};



#endif /* SERIALCONNECTIONS_H_ */
