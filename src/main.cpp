#include <Arduino.h>

/* Get tilt angles on X and Y, and rotation angle on Z
    Angles are given in degrees
 License: MIT
 */
 #include "Wire.h"
 #include <MPU6050_light.h>
 #include "Gimball.h"


 
  unsigned long timer = 0;
  MpuCustom mpu;
  Gimball gimball;


 void setup() 
 {
   mpu.init();
   Serial.begin(9600);
 }


 

 void loop()
  {
   mpu.update();
   if ((millis() - timer) > 500)
   { // print data every 10ms
      // gimball.resetPosition();
      // mpu.getMeans();
      
      gimball.resetPosition(mpu);
      gimball.printData();
      mpu.printData();
      timer = millis();
   }
  //  delay(1000);
 }