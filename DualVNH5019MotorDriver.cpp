#include <DualVNH5019MotorDriver.h>


DualVNH5019MotorDriver::DualVNH5019MotorDriver()
{
	//Pin map
	int ledPin = 13;
	int INB1 = 4;
	int INA1 = 2;
	int PWM1 = 9;
	int PWM2 = 10;
	int INA2 = 7;
	int INB2 = 8;
	int ENA1+ENB1 = 6;
	int ENA2+ENB2 = 12;
	pinMode(INB1,OUTPUT);
	pinMode(INA1,OUTPUT);
	pinMode(INA2,OUTPUT);
	pinMode(INB2,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(PWM2,OUTPUT);
	pinMode(ENA1+ENB1,OUTPUT);
	pinMode(ENA2+ENB2,OUTPUT);
	digitalWrite(INA1,HIGH);
	digitalWrite(INB1,LOW);
	digitalWrite(INA2,HIGH);
	digitalWrite(INB2,LOW);
	//LED
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, HIGH);
	//PWM
	TCCR1A = 0b10100000;// clkI/O /1 prescaler
	TCCR1B = 0b00010001;// 400 gives 20 kHz
	ICR1 = 400;
}

static void DualVNH5019MotorDriver::setM1Speed(int speed)
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
		TCCR1A = 0;
		setM1Brake(l);
	}
	else
	{
		TCCR1A = 0b10100000;// clkI/O /1 prescaler
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

static void DualVNH5019MotorDriver::setM2Speed(int speed)
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
		TCCR1B = 0;
		setM2Brake(l);
	}
	else
	{
		TCCR1B = 0b10100000;// clkI/O /1 prescaler
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

static void DualVNH5019MotorDriver::setSpeeds(int m1Speed, int m2Speed)
{
	setM1Speed(m1Speed);
	setM2Speed(m2Speed);
}

static void DualVNH5019MotorDriver::setM1Brake(unsigned char brake_mode)
{
	if (break_mode == 'c') //Coasting
	{
		digitalWrite(INA1, HIGH);
		digitalWrite(INB1, HIGH);
		digitalWrite(ENA1+ENB1, HIGH);
		digitalWrite(PWM1, LOW);
	}
	else if (break_mode == 'l') //Brake Low
	{
		digitalWrite(INA1, LOW);
		digitalWrite(INB1, LOW);
		digitalWrite(ENA1+ENB1, HIGH);
		digitalWrite(PWM1, HIGH);
	}
}

static void DualVNH5019MotorDriver::setM2Brake(unsigned char brake_mode)
{
	if (break_mode == 'c') //Coasting
	{
		digitalWrite(INA2, HIGH);
		digitalWrite(INB2, HIGH);
		digitalWrite(ENA2+ENB2, HIGH);
		digitalWrite(PWM2, LOW);
	}
	else if (break_mode == 'l') //Brake Low
	{
		digitalWrite(INA2, LOW);
		digitalWrite(INB2, LOW);
		digitalWrite(ENA2+ENB2, HIGH);
		digitalWrite(PWM2, HIGH);
	}
}



static void DualVNH5019MotorDriver::vbreak(unsigned char brake)
{
	setM1Brake(brake);
	setM2Brake(brake);
}



