#include <ESP32Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <ServoEasing.hpp>
#include "MpuCustom.h"

class Gimball{
public:

    Gimball()
    {
        servoX.attach(servoXPin, 90);
        servoY.attach(servoYPin, 90);
        servoZ.attach(servoZPin, 90);
        Serial.println("Servos setted successfully");
    }

    void resetPosition(MpuCustom& mpu)
    {
        getAngles(mpu);
        servoX.setEasingType(EASE_CUBIC_IN_OUT);
        servoX.easeTo(angleX, 40); 
        servoY.setEasingType(EASE_CUBIC_IN_OUT);
        servoY.easeTo(angleY, 45);
        servoZ.setEasingType(EASE_CUBIC_IN_OUT);
        servoZ.easeTo(angleZ, 45);
    }

    void printData()
    {
        Serial.println("Angles of the servos");
        Serial.print(angleX);
        Serial.print('\t');
        Serial.print(angleY);
        Serial.print('\t');
        Serial.println(angleZ);
    }


private:
    void getAngles(MpuCustom& mpu)
    {
        angleX = map(mpu.getRoll(), -90, 90, 0, 180);
        angleY = map(mpu.getPitch(), -90, 90, 0, 180);
        angleZ = map(mpu.getYaw(), -90, 90, 0, 180);
    }

private:
// Servos obyects.
    ServoEasing servoX;
    ServoEasing servoY;
    ServoEasing servoZ;
// Servos pins.
    const int servoXPin = 17;
    const int servoYPin = 18;
    const int servoZPin = 19;
// Servos angles.
    int angleX = 0;
    int angleY = 0; 
    int angleZ = 0;
};