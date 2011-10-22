#ifndef DualVNH5019MotorDriver_h
#define DualVNH5019MotorDriver_h

class DualVNH5019MotorDriver
{
	public:
	
		//CONSTRUCTORS
		DualVNH5019MotorDriver(); //default
		DualVNH5019MotorDriver(int INB1, int INA1, int INA2, int INB2); //
		// sets the motor speed.  The sign of 'speed' determines the direction
		// and the magnitude determines the speed.  limits: -400 <= speed <= 400
		// |speed| = 400 produces the maximum speed while speed = 0 is full brake.
		static void setM1Speed(int speed);
		static void setM2Speed(int speed);
		static void setSpeeds(int m1Speed, int m2Speed);
		static void setM1Brake(unsigned char brake_mode);
		static void setM2Brake(unsigned char brake_mode);
		static void setbreaks(unsigned char brake);// choose between coasting mode and brake low.
		
		
	private:
		
		
		static inline void int()
		{
			static unsigned char initialized = 0;
			
			if (!initialized)
			{
				initialized = 1;
				init2();
			}
		}
		
		// initializes timer 1 for proper PWM generation
		static void init2();
};

#endif