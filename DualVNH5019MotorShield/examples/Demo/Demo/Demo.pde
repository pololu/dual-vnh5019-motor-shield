#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

void setup()
{
  Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
}

void loop()
{
  for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    Serial.print("M1 current:");
    Serial.println(md.getM1CurrentMilliamps());
    delay(2);
  }
  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i);
    Serial.print("M1 current:");
    Serial.println(md.getM1CurrentMilliamps());
    delay(2);
  }
  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    Serial.print("M1 current:");
    Serial.println(md.getM1CurrentMilliamps());
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    md.setM2Speed(i);
    Serial.print("M2 current:");
    Serial.println(md.getM2CurrentMilliamps());
    delay(2);
  }
  for (int i = 400; i >= -400; i--)
  {
    md.setM2Speed(i);
    Serial.print("M2 current:");
    Serial.println(md.getM2CurrentMilliamps());
    delay(2);
  }
  for (int i = -400; i <= 0; i++)
  {
    md.setM2Speed(i);
    Serial.print("M2 current:");
    Serial.println(md.getM2CurrentMilliamps());
    delay(2);
  }
}
