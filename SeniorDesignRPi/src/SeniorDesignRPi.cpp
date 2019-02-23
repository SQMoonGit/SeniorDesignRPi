//============================================================================
// Name        : SeniorDesignRPi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Sensor.cpp"
#include "liftingProcess.cpp"
using namespace std;

class Slabbing
{
	private:
		SerialConnections check;
	public:
		Slabbing();
		void run();
	//private:

};


int main()
{
	Slabbing start;
	start.run();
	return 0;
}

Slabbing::Slabbing()
{

}

//Lift the slab
void Slabbing::run()
{

}
