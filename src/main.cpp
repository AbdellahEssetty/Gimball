#include <Arduino.h>

/* Get tilt angles on X and Y, and rotation angle on Z
    Angles are given in degrees
 License: MIT
 */
 #include <Wire.h>
 #include <MPU6050_light.h>
 #include "Gimball.h"
 #include <ServoEasing.hpp>



 
  unsigned long timer = 0;
  MpuCustom mpu;
  Gimball gimball;

  // ServoEasing servo;
  // // ServoCustom ss;

  // long i = 0;

 void setup() 
 {
   mpu.init();
  //  servo.attach(17, 45);
  //  ss.attach(18);
   Serial.begin(9600);
 }

 

 void loop()
  {
   mpu.update();
   if ((millis() - timer) > 10)
   { // print data every 10ms
      // gimball.resetPosition();
      mpu.getMeans();
      
      gimball.resetPosition(mpu);
      gimball.printData();
      mpu.printData();
      timer = millis();
   }
  //  delay(1000);

  // servo.setEasingFunction(EasingFunctions::linear);
  // servo.test();
  // delay(1000);



  // servo.setEasingType(EASE_CUBIC_IN_OUT); // EASE_LINEAR is default
  // servo.easeTo(135, 40); 
  // Serial.print(i++);                                // Blocking call
  // servo.startEaseTo(45, 40);  // Non blocking call
  // Serial.print('\t');
  // Serial.println(i++);
  // // Now the servo is moving to the end position independently of your program.
  // delay(5000);
  
  
 }