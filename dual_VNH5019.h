#ifndef VNH5019_h
#define VNH5019_h

class VNH5019
{
	public:
	
		//CONSTRUCTORS
		VNH5019();
		VNH5019(dutyA, dutyB); 
		
		// MODIFICATION MEMBER FUNCTIONS
		void on();
		void off();
		void PwmOn();
		void PwmOff();

	private:
		int dutyA; //DUTY CYCLE FOR MOTOR A 
		int dutyB; //DUTY CYCLE FOR MOTOR B
}