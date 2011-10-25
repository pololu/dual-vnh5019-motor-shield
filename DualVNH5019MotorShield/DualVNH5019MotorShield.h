#ifndef DualVNH5019MotorShield_h
#define DualVNH5019MotorShield_h
#include <WProgram.h>
#include "pins_arduino.h"

class DualVNH5019MotorShield
{
	public:
		//CONSTRUCTORS
		DualVNH5019MotorShield(); //default
		DualVNH5019MotorShield(int INB1, int INA1, int INA2, int INB2, int EN1, int EN2); //user define pins
		
		void init();
		
		// sets the motor speed.  The sign of 'speed' determines the direction
		// and the magnitude determines the speed.  limits: -400 <= speed <= 400
		// |speed| = 400 produces the maximum speed while speed = 0 is full brake.
		void setM1Speed(int speed);
		void setM2Speed(int speed);
		void setSpeeds(int m1Speed, int m2Speed);
		void setM1Brake(int coastDutyCycle);
		void setM2Brake(int coastDutyCycle);
		void brake(int coastDutyCycle);// choose between coasting mode and brake low.
		int getM1CurrentMilliamps();
		int getM2CurrentMilliamps();
		bool getM1Error();
		bool getM2Error();
		
	private:
		int INB1;
		int INA1;
		int PWM1;
		int PWM2;
		int INA2;
		int INB2;
		int EN1DIAG1;
		int EN2DIAG2;
		int CS1;
		int CS2;
		
		
};

#endif