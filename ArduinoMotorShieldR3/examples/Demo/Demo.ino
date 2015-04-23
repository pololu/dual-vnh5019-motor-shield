#include "ArduinoMotorShieldR3.h"

ArduinoMotorShieldR3 md;

void setup()
{
  Serial.begin(115200);
  Serial.println("Arduino Motor Shield R3");
  md.init();
}

void loop()
{
  Serial.println("M1 Speed 100% Forward");
  md.setM1Speed(400);
  Serial.println("M2 Speed 100% Forward");
  md.setM2Speed(400);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);

  Serial.println("M1 Speed 100% Backward");
  md.setM1Speed(-400);
  Serial.println("M2 Speed 100% Backward");
  md.setM2Speed(-400);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
  
  Serial.println("M1 Speed 50% Forward");
  md.setM1Speed(200);
  Serial.println("M2 Speed 50% Forward");
  md.setM2Speed(200);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);

  Serial.println("M1 Speed 50% Backward");
  md.setM1Speed(-200);
  Serial.println("M2 Speed 50% Backward");
  md.setM2Speed(-200);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
  
  Serial.println("M1 Speed 0%");
  md.setM1Speed(0);
  Serial.println("M2 Speed 0%");
  md.setM2Speed(0);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
}
