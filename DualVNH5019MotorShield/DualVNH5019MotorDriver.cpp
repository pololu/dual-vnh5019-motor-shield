#include "DualVNH5019MotorDriver.h"
#include "pins_arduino.h"

DualVNH5019MotorDriver::DualVNH5019MotorDriver()
{
	//Pin map
	ledPin = 13;
	INB1 = 4;
	INA1 = 2;
	PWM1 = 9;
	PWM2 = 10;
	INA2 = 7;
	INB2 = 8;
	ENA1ENB1 = 6;
	ENA2ENB2 = 12;
	pinMode(INB1,OUTPUT);
	pinMode(INA1,OUTPUT);
	pinMode(INA2,OUTPUT);
	pinMode(INB2,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(PWM2,OUTPUT);
	//PWM
	TCCR1A = 0b10100000;// clkI/O /1 prescaler
	TCCR1B = 0b00010001;// 400 gives 20 kHz
	ICR1 = 400;
}

DualVNH5019MotorDriver::DualVNH5019MotorDriver(int _ledpin, int _inb1, int _ina1, int _ina2, int _inb2, int _ena1enb1, int _ena2enb2)
{
	//Pin map
	ledPin = _ledpin;
	INB1 = _inb1;
	INA1 = _ina1;
	PWM1 = 9;
	PWM2 = 10;
	INA2 = _ina2;
	INB2 = _inb2;
	ENA1ENB1 = _ena1enb1;
	ENA2ENB2 = _ena2enb2;
	pinMode(INB1,OUTPUT);
	pinMode(INA1,OUTPUT);
	pinMode(INA2,OUTPUT);
	pinMode(INB2,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(PWM2,OUTPUT);
	//PWM
	TCCR1A = 0b10100000;// clkI/O /1 prescaler
	TCCR1B = 0b00010001;// 400 gives 20 kHz
	ICR1 = 400;
}


void DualVNH5019MotorDriver::setM1Speed(int speed)
{
	unsigned char reverse = 0;
	
	if (speed < 0)
	{
		speed = -speed;	// make speed a positive quantity
		reverse = 1;	// preserve the direction
	}
	if (speed > 400)	// Max PWM dutycycle
		speed = 400;
	OCR1A = speed;
	if (speed == 0)
	{
		//TCCR1A = 0;
		setM1Brake(0);
	}
	else
	{
		//TCCR1A = 0b10100000;// clkI/O /1 prescaler
		if (reverse)
		{
			digitalWrite(INA1,LOW);
			digitalWrite(INB1,HIGH);
		}
		else
		{
			digitalWrite(INA1,HIGH);
			digitalWrite(INB1,LOW);
		}
	}
}

void DualVNH5019MotorDriver::setM2Speed(int speed)
{
	unsigned char reverse = 0;
	
	if (speed < 0)
	{
		speed = -speed;	// make speed a positive quantity
		reverse = 1;	// preserve the direction
	}
	if (speed > 400)	// Max 
		speed = 400;
	OCR1B = speed;
	if (speed == 0)
	{
		//TCCR1B = 0;
		setM2Brake(0);
	}
	else
	{
		//TCCR1B = 0b10100000;// clkI/O /1 prescaler
		if (reverse)
		{
			digitalWrite(INA2,LOW);
			digitalWrite(INB2,HIGH);
		}
		else
		{
			digitalWrite(INA2,HIGH);
			digitalWrite(INB2,LOW);
		}
	}
}

void DualVNH5019MotorDriver::setSpeeds(int m1Speed, int m2Speed)
{
	setM1Speed(m1Speed);
	setM2Speed(m2Speed);
}

// coastDutyCycle is a number between 0 and 400
void DualVNH5019MotorDriver::setM1Brake(int coastDutyCycle)
{
	digitalWrite(INA1, LOW);
	digitalWrite(INB1, LOW);
	OCR1A = coastDutyCycle;
}

// coastDutyCycle is a number between 0 and 400
void DualVNH5019MotorDriver::setM2Brake(int coastDutyCycle)
{
	digitalWrite(INA2, LOW);
	digitalWrite(INB2, LOW);
	OCR1B = coastDutyCycle;
}

void DualVNH5019MotorDriver::brake(int coastDutyCycle)
{
	setM1Brake(coastDutyCycle);
	setM2Brake(coastDutyCycle);
}

int DualVNH5019MotorDriver::getM1CurrentMilliamps()
{
	return analogRead(0) * 23;
}

int DualVNH5019MotorDriver::getM2CurrentMilliamps()
{
	return analogRead(1) * 23;
}
