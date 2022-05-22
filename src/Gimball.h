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
        servoX.setEasingType(EASE_QUARTIC_OUT);
        // servoX.easeTo(angleX, 80); 
        servoX.startEaseTo(angleX, 45);
        servoY.setEasingType(EASE_QUARTIC_OUT);
        // servoY.easeTo(angleY, 80);
        servoY.startEaseTo(angleY, 45);
        servoZ.setEasingType(EASE_QUARTIC_OUT);
        // servoZ.easeTo(angleZ, 80);
        servoZ.startEaseTo(angleZ, 45);
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