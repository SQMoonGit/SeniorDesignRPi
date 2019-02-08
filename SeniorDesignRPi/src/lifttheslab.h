#include "serialconnections.h"

class LiftTheSlab
{
private:
  
  double FinalHeight;                   //Final height variable
  double calculateFinalHeight();        //Calculate the final height
  boolean valveSwitch();                //Switch the valve on and off
                          
public:
  LiftTheSlab();                        //default constructor
  ~LiftTheSlab();                       //deconstructor
  double sensorHeight();                //Get the sensor height
  double getFinalHeight();              //Get the final height
  boolean getValveValue();              //Get the value of the valve
  void lift();                          //main algorithm for lifting the slab
}
