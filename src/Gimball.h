#include <ESP32Servo.h>
#include <Arduino.h>
#include "Wire.h"
#include <MPU6050_light.h>
#include "MpuCustom.h"

class Gimball{
public:

    Gimball()
    {
        servoX.attach(servoXPin);
        servoY.attach(servoYPin);
        servoZ.attach(servoZPin);
        Serial.println("Servos setted successfully");
    }

    void resetPosition(MpuCustom& mpu)
    {
        getAngles(mpu);
        servoX.write(angleX);
        servoY.write(angleY);
        servoZ.write(angleZ);
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
    Servo servoX;
    Servo servoY;
    Servo servoZ;
// Servos pins.
    const int servoXPin = 17;
    const int servoYPin = 18;
    const int servoZPin = 19;
// Servos angles.
    int angleX = 0;
    int angleY = 0; 
    int angleZ = 0;
};