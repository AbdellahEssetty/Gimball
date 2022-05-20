#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>


class MpuCustom{
public:

    MpuCustom()
    {
        Wire.begin();
    }

    void init()
    {
        byte status = mpu.begin();
        Serial.print(F("MPU6050 status: "));
        Serial.println(status);
        while (status != 0) { } // stop everything if could not connect to MPU6050
        Serial.println(F("Calculating offsets, do not move MPU6050"));
        
        delay(1000);
        mpu.calcOffsets(); // gyro and accelero
        Serial.println("Done!\n");
    }


    void update()
    {
        mpu.update();
    }

    void printData()
    {
        getMeans();
        Serial.print("X : ");
        Serial.print(meanX);
        Serial.print("\tY : ");
        Serial.print(meanY);
        Serial.print("\tZ : ");
        Serial.println(meanZ);
    }
 
    void getMeans()
    {
        const size_t meanSize = 100;
        for(size_t i = 0; i <= meanSize; i++)
        {
            meanX += mpu.getAngleX();
            meanY += mpu.getAngleY();
            meanZ += mpu.getAngleZ();
        }

        meanX /= meanSize;
        meanY /= meanSize;
        meanZ /= meanSize;

        roll = meanX;
        pitch = meanY;
        yaw = meanZ;
    }

    double getRoll() const
    {
        return roll;
    }
    double getPitch() const
    {
        return pitch;
    }
    double getYaw() const
    {
        return yaw;
    }
private:
// angles from the mpu. !!!! Be aware of the yaw, very inpredictible.
    double roll = 0.0;
    double pitch = 0.0;
    double yaw = 0.0;

// getting the mean of the angles, hopefully getting the data better.
    double meanX = 0.0;
    double meanY = 0.0;
    double meanZ = 0.0;

    MPU6050 mpu = MPU6050(Wire);
};