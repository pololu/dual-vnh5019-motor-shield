#ifndef DualVNH5019MotorDriver_h
#define DualVNH5019MotorDriver_h
#include <WProgram.h>

class DualVNH5019MotorDriver
{
	public:
	
		//CONSTRUCTORS
		DualVNH5019MotorDriver(); //default
		DualVNH5019MotorDriver(int _led, int _inb1, int _ina1, int _ina2, int _inb2, int _ena1enb1, int _ena2enb2); //user define pins
		// sets the motor speed.  The sign of 'speed' determines the direction
		// and the magnitude determines the speed.  limits: -400 <= speed <= 400
		// |speed| = 400 produces the maximum speed while speed = 0 is full brake.
		void setM1Speed(int speed);
		void setM2Speed(int speed);
		void setSpeeds(int m1Speed, int m2Speed);
		void setM1Brake(int coastDutyCycle);
		void setM2Brake(int coastDutyCycle);
		void brake(int coastDutyCycle);// choose between coasting mode and brake low.
		
	private:
	
		/*int ledPin = 13;
		int INB1 = 4;
		int INA1 = 2;
		int PWM1 = 9;
		int PWM2 = 10;
		int INA2 = 7;
		int INB2 = 8;
		int ENA1ENB1 = 6;
		int ENA2ENB2 = 12;*/
		int ledPin;
		int INB1;
		int INA1;
		int PWM1;
		int PWM2;
		int INA2;
		int INB2;
		int ENA1ENB1;
		int ENA2ENB2;
		
		
		
};

#endif