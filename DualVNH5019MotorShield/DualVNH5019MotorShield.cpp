#include "DualVNH5019MotorShield.h"
#include "pins_arduino.h"

DualVNH5019MotorShield::DualVNH5019MotorShield()
{
	//Pin map
	INB1 = 4;
	INA1 = 2;
	INA2 = 7;
	INB2 = 8;
	EN1DIAG1 = 6;
	EN2DIAG2 = 12;
	PWM1 = 9;
	PWM2 = 10;
	CS1 = 0;
	CS2 = 1;
}

DualVNH5019MotorShield::DualVNH5019MotorShield(int _INB1, int _INA1, int _INA2, int _INB2, int _EN1, int _EN2)
{
	//Pin map
	INB1 = _INB1;
	INA1 = _INA1;
	INA2 = _INA2;
	INB2 = _INB2;
	EN1DIAG1 = _EN1;
	EN2DIAG2 = _EN2;
	//PWM1 and PWM2 cannot be remapped because the library assumes PWM is on timer1
	PWM1 = 9;
	PWM2 = 10;
}

void DualVNH5019MotorShield::init()
{
	pinMode(INB1,OUTPUT);
	pinMode(INA1,OUTPUT);
	pinMode(INA2,OUTPUT);
	pinMode(INB2,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(PWM2,OUTPUT);
	pinMode(EN1DIAG1,INPUT);
	pinMode(EN2DIAG2,INPUT);
	pinMode(CS1,INPUT);
	pinMode(CS2,INPUT);
	//PWM
	TCCR1A = 0b10100000;// clkI/O /1 prescaler
	TCCR1B = 0b00010001;
	ICR1 = 400; // 400 gives 20kHz
}

void DualVNH5019MotorShield::setM1Speed(int speed)
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
		setM1Brake(0);
	}
	else
	{
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

void DualVNH5019MotorShield::setM2Speed(int speed)
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
		setM2Brake(0);
	}
	else
	{
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

void DualVNH5019MotorShield::setSpeeds(int m1Speed, int m2Speed)
{
	setM1Speed(m1Speed);
	setM2Speed(m2Speed);
}

// coastDutyCycle is a number between 0 and 400
void DualVNH5019MotorShield::setM1Brake(int coastDutyCycle)
{
	// normalize coastDutyCycle
	if (coastDutyCycle < 0)
	{
		coastDutyCycle = -coastDutyCycle;
	}
	if (coastDutyCycle > 400)	// Max dutyCycle
		coastDutyCycle = 400;
	digitalWrite(INA1, LOW);
	digitalWrite(INB1, LOW);
	OCR1A = coastDutyCycle;
}

// coastDutyCycle is a number between 0 and 400
void DualVNH5019MotorShield::setM2Brake(int coastDutyCycle)
{
	// normalize coastDutyCycle
	if (coastDutyCycle < 0)
	{
		coastDutyCycle = -coastDutyCycle;
	}
	if (coastDutyCycle > 400)	// Max dutyCycle
		coastDutyCycle = 400;
	digitalWrite(INA2, LOW);
	digitalWrite(INB2, LOW);
	OCR1B = coastDutyCycle;
}

void DualVNH5019MotorShield::brake(int coastDutyCycle)
{
	setM1Brake(coastDutyCycle);
	setM2Brake(coastDutyCycle);
}

int DualVNH5019MotorShield::getM1CurrentMilliamps()
{
	return analogRead(CS1) * 23;
}

int DualVNH5019MotorShield::getM2CurrentMilliamps()
{
	return analogRead(CS2) * 23;
}

bool DualVNH5019MotorShield::getM1Error()
{
	return digitalRead(EN1DIAG1);
}

bool DualVNH5019MotorShield::getM2Error()
{
	return digitalRead(EN2DIAG2);
}
